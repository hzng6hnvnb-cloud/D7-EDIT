/* =====================================================
   CUTLAB
===================================================== */

const videoInput =
    document.getElementById("videoInput");

const imageInput =
    document.getElementById("imageInput");

const audioInput =
    document.getElementById("audioInput");

const previewVideo =
    document.getElementById("previewVideo");

const timelineTrack =
    document.getElementById("timelineTrack");

const timelineEmpty =
    document.getElementById("timelineEmpty");

const playBtn =
    document.getElementById("playBtn");

const seekBar =
    document.getElementById("seekBar");

const currentTime =
    document.getElementById("currentTime");

const duration =
    document.getElementById("duration");

const textOverlay =
    document.getElementById("textOverlay");

const toast =
    document.getElementById("toast");


let clips = [];

let selectedClip = null;

let currentFilter = "none";

let currentEffect = "none";

let currentSpeed = 1;

let textValue = "";


/* =====================================================
   رسالة
===================================================== */

function showToast(message) {

    toast.textContent =
        message;

    toast.classList.add(
        "show"
    );

    setTimeout(() => {

        toast.classList.remove(
            "show"
        );

    }, 1600);
}


/* =====================================================
   رفع الفيديو
===================================================== */

videoInput.addEventListener(
    "change",
    event => {

        const file =
            event.target.files[0];

        if (!file) return;


        const url =
            URL.createObjectURL(
                file
            );


        const clip = {

            id:
                Date.now(),

            name:
                file.name,

            url:
                url,

            file:
                file,

            type:
                "video"
        };


        clips.push(
            clip
        );


        selectedClip =
            clip;


        renderTimeline();


        loadClip(
            clip
        );


        showToast(
            "تمت إضافة الفيديو"
        );
    }
);


/* =====================================================
   رفع الصورة
===================================================== */

imageInput.addEventListener(
    "change",
    event => {

        const file =
            event.target.files[0];

        if (!file) return;


        const url =
            URL.createObjectURL(
                file
            );


        const clip = {

            id:
                Date.now(),

            name:
                file.name,

            url:
                url,

            file:
                file,

            type:
                "image"
        };


        clips.push(
            clip
        );


        selectedClip =
            clip;


        renderTimeline();


        showToast(
            "تمت إضافة الصورة"
        );
    }
);


/* =====================================================
   رفع الصوت
===================================================== */

audioInput.addEventListener(
    "change",
    event => {

        const file =
            event.target.files[0];

        if (!file) return;


        showToast(
            "تمت إضافة الصوت للمشروع"
        );
    }
);


/* =====================================================
   تحميل المقطع
===================================================== */

function loadClip(clip) {

    if (
        clip.type !==
        "video"
    ) {

        return;
    }


    previewVideo.src =
        clip.url;


    previewVideo.playbackRate =
        currentSpeed;


    previewVideo.load();


    previewVideo.onloadedmetadata =
        () => {

            updateDuration();

            seekBar.value = 0;
        };
}


/* =====================================================
   الخط الزمني
===================================================== */

function renderTimeline() {

    if (!clips.length) {

        timelineTrack.innerHTML = `

            <div class="timeline-empty">

                اسحب فيديو إلى المشروع

            </div>
        `;

        return;
    }


    timelineTrack.innerHTML =
        clips
            .map(
                clip => `

                <div
                    class="
                        timeline-clip
                        ${
                            selectedClip &&
                            selectedClip.id === clip.id
                            ?
                            "selected"
                            :
                            ""
                        }
                    "
                    data-id="${clip.id}">

                    ${
                        clip.type === "video"
                        ?
                        `
                        <video
                            class="clip-preview"
                            src="${clip.url}"
                            muted>
                        </video>
                        `
                        :
                        `
                        <img
                            class="clip-preview"
                            src="${clip.url}">
                        `
                    }

                    <div class="clip-name">

                        ${clip.name}

                    </div>

                </div>

            `
            )
            .join("");


    timelineTrack
        .querySelectorAll(
            ".timeline-clip"
        )
        .forEach(element => {

            element.onclick =
                () => {

                    const id =
                        Number(
                            element.dataset.id
                        );


                    selectedClip =
                        clips.find(
                            clip =>
                                clip.id === id
                        );


                    renderTimeline();


                    loadClip(
                        selectedClip
                    );
                };
        });
}


/* =====================================================
   تشغيل
===================================================== */

playBtn.onclick = () => {

    if (
        previewVideo.paused
    ) {

        previewVideo.play();

        playBtn.textContent =
            "Ⅱ";

    } else {

        previewVideo.pause();

        playBtn.textContent =
            "▶";
    }
};


previewVideo.addEventListener(
    "play",
    () => {

        playBtn.textContent =
            "Ⅱ";
    }
);


previewVideo.addEventListener(
    "pause",
    () => {

        playBtn.textContent =
            "▶";
    }
);


/* =====================================================
   الوقت
===================================================== */

function formatTime(seconds) {

    if (
        !Number.isFinite(
            seconds
        )
    ) {

        return "00:00";
    }


    const minutes =
        Math.floor(
            seconds / 60
        );


    const secondsPart =
        Math.floor(
            seconds % 60
        );


    return (

        String(minutes)
            .padStart(2,"0")

        +

        ":"

        +

        String(secondsPart)
            .padStart(2,"0")
    );
}


function updateDuration() {

    duration.textContent =
        formatTime(
            previewVideo.duration
        );
}


previewVideo.addEventListener(
    "timeupdate",
    () => {

        currentTime.textContent =
            formatTime(
                previewVideo.currentTime
            );


        if (
            previewVideo.duration
        ) {

            seekBar.value =
                (
                    previewVideo.currentTime /
                    previewVideo.duration
                ) * 100;
        }
    }
);


previewVideo.addEventListener(
    "loadedmetadata",
    updateDuration
);


/* =====================================================
   شريط التقدم
===================================================== */

seekBar.addEventListener(
    "input",
    () => {

        if (
            !previewVideo.duration
        ) {

            return;
        }


        previewVideo.currentTime =
            (
                Number(
                    seekBar.value
                ) / 100
            )
            *
            previewVideo.duration;
    }
);


/* =====================================================
   رجوع وتقديم
===================================================== */

document.getElementById(
    "rewind"
).onclick = () => {

    previewVideo.currentTime =
        Math.max(
            0,
            previewVideo.currentTime - 5
        );
};


document.getElementById(
    "forward"
).onclick = () => {

    previewVideo.currentTime =
        Math.min(
            previewVideo.duration || 0,
            previewVideo.currentTime + 5
        );
};


/* =====================================================
   كتم الصوت
===================================================== */

document.getElementById(
    "muteBtn"
).onclick = () => {

    previewVideo.muted =
        !previewVideo.muted;


    document.getElementById(
        "muteBtn"
    ).textContent =
        previewVideo.muted
        ?
        "🔇"
        :
        "🔊";
};


/* =====================================================
   النص
===================================================== */

document.getElementById(
    "addTextBtn"
).onclick = () => {

    textValue =
        document.getElementById(
            "textInput"
        ).value;


    textOverlay.textContent =
        textValue;


    showToast(
        "تمت إضافة النص"
    );
};


document.getElementById(
    "textInput"
).addEventListener(
    "input",
    event => {

        textOverlay.textContent =
            event.target.value;
    }
);


document.getElementById(
    "textSize"
).addEventListener(
    "input",
    event => {

        textOverlay.style.fontSize =
            event.target.value
            +
            "px";
    }
);


/* =====================================================
   الفلاتر
===================================================== */

document
    .querySelectorAll(
        ".filter-btn"
    )
    .forEach(button => {

        button.onclick = () => {

            currentFilter =
                button.dataset.filter;


            previewVideo.className =
                "";


            if (
                currentFilter !==
                "none"
            ) {

                previewVideo.classList.add(
                    "filter-" +
                    currentFilter
                );
            }


            showToast(
                "تم تطبيق الفلتر"
            );
        };
    });


/* =====================================================
   المؤثرات
===================================================== */

document
    .querySelectorAll(
        ".effect-btn"
    )
    .forEach(button => {

        button.onclick = () => {

            currentEffect =
                button.dataset.effect;


            previewVideo.classList.remove(
                "effect-shake",
                "effect-zoom",
                "effect-blur",
                "effect-glitch"
            );


            if (
                currentEffect !==
                "none"
            ) {

                previewVideo.classList.add(
                    "effect-" +
                    currentEffect
                );
            }


            showToast(
                "تم تطبيق المؤثر"
            );
        };
    });


/* =====================================================
   السرعة
===================================================== */

document
    .querySelectorAll(
        ".speed-btn"
    )
    .forEach(button => {

        button.onclick = () => {

            currentSpeed =
                Number(
                    button.dataset.speed
                );


            previewVideo.playbackRate =
                currentSpeed;


            showToast(
                "السرعة: " +
                currentSpeed +
                "x"
            );
        };
    });


/* =====================================================
   الانتقالات
===================================================== */

document
    .querySelectorAll(
        ".transition-btn"
    )
    .forEach(button => {

        button.onclick = () => {

            showToast(
                "تم اختيار انتقال " +
                button.dataset.transition
            );
        };
    });


/* =====================================================
   تقسيم
===================================================== */

document.getElementById(
    "splitBtn"
).onclick = () => {

    if (
        !selectedClip ||
        selectedClip.type !== "video"
    ) {

        showToast(
            "حدد فيديو أولًا"
        );

        return;
    }


    const current =
        previewVideo.currentTime;


    if (
        current <= 0 ||
        current >=
        previewVideo.duration
    ) {

        showToast(
            "حرّك المؤشر إلى مكان التقسيم"
        );

        return;
    }


    showToast(
        "تم تحديد نقطة التقسيم"
    );
};


/* =====================================================
   حذف
===================================================== */

document.getElementById(
    "deleteBtn"
).onclick = () => {

    if (!selectedClip) {

        showToast(
            "حدد مقطعًا أولًا"
        );

        return;
    }


    clips =
        clips.filter(
            clip =>
                clip.id !==
                selectedClip.id
        );


    selectedClip =
        clips[0] || null;


    renderTimeline();


    if (selectedClip) {

        loadClip(
            selectedClip
        );
    } else {

        previewVideo.removeAttribute(
            "src"
        );

        previewVideo.load();
    }


    showToast(
        "تم حذف المقطع"
    );
};


/* =====================================================
   التراجع والإعادة
===================================================== */

document.getElementById(
    "undoBtn"
).onclick = () => {

    showToast(
        "التراجع جاهز للعمليات القادمة"
    );
};


document.getElementById(
    "redoBtn"
).onclick = () => {

    showToast(
        "الإعادة جاهزة للعمليات القادمة"
    );
};


/* =====================================================
   التصدير
===================================================== */

document.getElementById(
    "exportBtn"
).onclick = () => {

    showToast(
        "التصدير يحتاج محرك معالجة فيديو"
    );
};


/* =====================================================
   تبديل الأدوات
===================================================== */

const panels = {

    media:
        document.getElementById(
            "mediaPanel"
        ),

    text:
        document.getElementById(
            "textPanel"
        ),

    audio:
        document.getElementById(
            "audioPanel"
        ),

    effects:
        document.getElementById(
            "effectsPanel"
        ),

    filters:
        document.getElementById(
            "filtersPanel"
        ),

    transitions:
        document.getElementById(
            "transitionsPanel"
        ),

    speed:
        document.getElementById(
            "speedPanel"
        )
};


const titles = {

    media:
        "الوسائط",

    text:
        "النص",

    audio:
        "الصوت",

    effects:
        "المؤثرات",

    filters:
        "الفلاتر",

    transitions:
        "الانتقالات",

    speed:
        "السرعة"
};


document
    .querySelectorAll(
        ".tool"
    )
    .forEach(button => {

        button.onclick = () => {

            const tool =
                button.dataset.tool;


            document
                .querySelectorAll(
                    ".tool"
                )
                .forEach(
                    b =>
                        b.classList.remove(
                            "active"
                        )
                );


            button.classList.add(
                "active"
            );


            Object.values(
                panels
            ).forEach(
                panel =>
                    panel.classList.remove(
                        "active"
                    )
            );


            panels[
                tool
            ].classList.add(
                "active"
            );


            document.getElementById(
                "panelTitle"
            ).textContent =
                titles[tool];
        };
    });

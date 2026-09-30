const videoInput = document.getElementById("videoInput");
const imageInput = document.getElementById("imageInput");
const audioInput = document.getElementById("audioInput");

const video = document.getElementById("video");
const imagePreview = document.getElementById("imagePreview");

const emptyPreview = document.getElementById("emptyPreview");
const textOverlay = document.getElementById("textOverlay");

const track = document.getElementById("track");
const assetList = document.getElementById("assetList");

const playBtn = document.getElementById("play");
const seek = document.getElementById("seek");

const currentTime = document.getElementById("currentTime");
const totalTime = document.getElementById("totalTime");

const toast = document.getElementById("toast");

let clips = [];
let selectedClip = null;

let currentEffect = "none";
let currentFilter = "none";
let currentSpeed = 1;

let history = [];
let future = [];


/* ======================================
   الرسائل
====================================== */

function notify(text) {

    toast.textContent = text;

    toast.classList.add("show");

    setTimeout(() => {
        toast.classList.remove("show");
    }, 1600);
}


/* ======================================
   الوقت
====================================== */

function formatTime(seconds) {

    if (!Number.isFinite(seconds)) {
        return "00:00";
    }

    const m =
        Math.floor(seconds / 60)
            .toString()
            .padStart(2, "0");

    const s =
        Math.floor(seconds % 60)
            .toString()
            .padStart(2, "0");

    return `${m}:${s}`;
}


/* ======================================
   حفظ الحالة
====================================== */

function saveHistory() {

    history.push(
        JSON.stringify(
            clips.map(c => ({
                id: c.id,
                name: c.name,
                url: c.url,
                type: c.type
            }))
        )
    );

    if (history.length > 30) {
        history.shift();
    }

    future = [];
}


/* ======================================
   رفع الفيديو
====================================== */

videoInput.addEventListener(
    "change",
    function () {

        const file = this.files[0];

        if (!file) return;

        const url =
            URL.createObjectURL(file);

        const clip = {

            id: Date.now(),

            name: file.name,

            url: url,

            type: "video",

            file: file
        };

        saveHistory();

        clips.push(clip);

        selectedClip = clip;

        renderAll();

        loadClip(clip);

        notify("تمت إضافة الفيديو ✓");
    }
);


/* ======================================
   رفع الصورة
====================================== */

imageInput.addEventListener(
    "change",
    function () {

        const file = this.files[0];

        if (!file) return;

        const url =
            URL.createObjectURL(file);

        const clip = {

            id: Date.now(),

            name: file.name,

            url: url,

            type: "image",

            file: file
        };

        saveHistory();

        clips.push(clip);

        selectedClip = clip;

        renderAll();

        loadClip(clip);

        notify("تمت إضافة الصورة ✓");
    }
);


/* ======================================
   الصوت
====================================== */

audioInput.addEventListener(
    "change",
    function () {

        if (!this.files[0]) return;

        notify("تمت إضافة الصوت ✓");
    }
);


/* ======================================
   تحميل المقطع
====================================== */

function loadClip(clip) {

    if (!clip) return;

    video.className = "";
    video.style.filter = "";
    video.style.transform = "";

    imagePreview.style.display = "none";

    emptyPreview.style.display = "none";

    if (clip.type === "video") {

        video.style.display = "block";

        video.src = clip.url;

        video.playbackRate =
            currentSpeed;

        video.load();

    } else {

        video.pause();

        video.style.display = "none";

        imagePreview.src =
            clip.url;

        imagePreview.style.display =
            "block";
    }

    applyVisuals();
}


/* ======================================
   عرض الخط الزمني
====================================== */

function renderTimeline() {

    track.innerHTML = "";

    clips.forEach(clip => {

        const element =
            document.createElement("div");

        element.className =
            "timeline-clip";

        if (
            selectedClip &&
            clip.id === selectedClip.id
        ) {
            element.classList.add(
                "selected"
            );
        }

        if (clip.type === "video") {

            const v =
                document.createElement("video");

            v.src = clip.url;

            v.muted = true;

            element.appendChild(v);

        } else {

            const img =
                document.createElement("img");

            img.src = clip.url;

            element.appendChild(img);
        }

        const name =
            document.createElement("div");

        name.className =
            "timeline-name";

        name.textContent =
            clip.name;

        element.appendChild(name);

        element.onclick = () => {

            selectedClip = clip;

            renderTimeline();

            loadClip(clip);
        };

        track.appendChild(element);
    });

    document.getElementById(
        "clipCount"
    ).textContent =
        `${clips.length} مقطع`;
}


/* ======================================
   قائمة الملفات
====================================== */

function renderAssets() {

    assetList.innerHTML = "";

    clips.forEach(clip => {

        const item =
            document.createElement("div");

        item.className =
            "asset";

        const thumb =
            document.createElement(
                clip.type === "video"
                    ? "video"
                    : "img"
            );

        thumb.className =
            "asset-thumb";

        thumb.src =
            clip.url;

        if (clip.type === "video") {
            thumb.muted = true;
        }

        const name =
            document.createElement("div");

        name.className =
            "asset-name";

        name.textContent =
            clip.name;

        item.appendChild(thumb);
        item.appendChild(name);

        item.onclick = () => {

            selectedClip = clip;

            renderTimeline();

            loadClip(clip);
        };

        assetList.appendChild(item);
    });
}


function renderAll() {

    renderTimeline();

    renderAssets();
}


/* ======================================
   التشغيل
====================================== */

playBtn.onclick = () => {

    if (!video.src) {

        notify("أضف فيديو أولًا");

        return;
    }

    if (video.paused) {

        video.play();

        playBtn.textContent =
            "Ⅱ";

    } else {

        video.pause();

        playBtn.textContent =
            "▶";
    }
};


video.addEventListener(
    "play",
    () => {
        playBtn.textContent = "Ⅱ";
    }
);


video.addEventListener(
    "pause",
    () => {
        playBtn.textContent = "▶";
    }
);


/* ======================================
   الوقت
====================================== */

video.addEventListener(
    "loadedmetadata",
    () => {

        totalTime.textContent =
            formatTime(video.duration);
    }
);


video.addEventListener(
    "timeupdate",
    () => {

        currentTime.textContent =
            formatTime(video.currentTime);

        if (video.duration) {

            seek.value =
                (
                    video.currentTime /
                    video.duration
                ) * 100;
        }
    }
);


/* ======================================
   شريط التقدم
====================================== */

seek.addEventListener(
    "input",
    () => {

        if (!video.duration) return;

        video.currentTime =
            (
                Number(seek.value) /
                100
            ) *
            video.duration;
    }
);


/* ======================================
   تقديم وتأخير
====================================== */

document.getElementById(
    "back5"
).onclick = () => {

    video.currentTime =
        Math.max(
            0,
            video.currentTime - 5
        );
};


document.getElementById(
    "next5"
).onclick = () => {

    video.currentTime =
        Math.min(
            video.duration || 0,
            video.currentTime + 5
        );
};


/* ======================================
   الصوت
====================================== */

document.getElementById(
    "mute"
).onclick = function () {

    video.muted =
        !video.muted;

    this.textContent =
        video.muted
            ? "🔇"
            : "🔊";
};


/* ======================================
   النص
====================================== */

document.getElementById(
    "addText"
).onclick = () => {

    const value =
        document.getElementById(
            "textInput"
        ).value;

    textOverlay.textContent =
        value || "عنوان جديد";

    notify("تمت إضافة النص ✓");
};


document.getElementById(
    "textInput"
).addEventListener(
    "input",
    function () {

        textOverlay.textContent =
            this.value;
    }
);


document.getElementById(
    "textSize"
).addEventListener(
    "input",
    function () {

        textOverlay.style.fontSize =
            this.value + "px";
    }
);


/* ======================================
   المؤثرات
====================================== */

document
    .querySelectorAll(".effect-card")
    .forEach(button => {

        button.onclick = () => {

            currentEffect =
                button.dataset.effect;

            applyVisuals();

            notify(
                "تم تطبيق المؤثر ✓"
            );
        };
    });


/* ======================================
   الفلاتر
====================================== */

document
    .querySelectorAll(".filter-card")
    .forEach(button => {

        button.onclick = () => {

            currentFilter =
                button.dataset.filter;

            applyVisuals();

            notify(
                "تم تطبيق الفلتر ✓"
            );
        };
    });


function applyVisuals() {

    video.className = "";

    let filter = "";

    if (currentFilter === "cinema") {

        filter =
            "contrast(1.2) saturate(.85) brightness(.9)";
    }

    if (currentFilter === "bw") {

        filter =
            "grayscale(1)";
    }

    if (currentFilter === "warm") {

        filter =
            "sepia(.3) saturate(1.25)";
    }

    if (currentFilter === "cool") {

        filter =
            "hue-rotate(18deg) saturate(.9)";
    }

    if (currentFilter === "vivid") {

        filter =
            "saturate(1.7) contrast(1.1)";
    }

    video.style.filter =
        filter;


    if (
        currentEffect !== "none"
    ) {

        video.classList.add(
            "effect-" +
            currentEffect
        );
    }
}


/* ======================================
   السرعة
====================================== */

document
    .querySelectorAll(
        ".speed-grid button"
    )
    .forEach(button => {

        button.onclick = () => {

            currentSpeed =
                Number(
                    button.dataset.speed
                );

            video.playbackRate =
                currentSpeed;

            notify(
                `السرعة ${currentSpeed}×`
            );
        };
    });


/* ======================================
   الانتقالات
====================================== */

document
    .querySelectorAll(
        ".transition-item"
    )
    .forEach(button => {

        button.onclick = () => {

            notify(
                "تم اختيار الانتقال ✓"
            );
        };
    });


/* ======================================
   الخصائص
====================================== */

function updateTransform() {

    const scale =
        Number(
            document.getElementById(
                "scale"
            ).value
        );

    const rotate =
        Number(
            document.getElementById(
                "rotate"
            ).value
        );

    video.style.transform =
        `scale(${scale / 100}) rotate(${rotate}deg)`;
}


document.getElementById(
    "scale"
).addEventListener(
    "input",
    updateTransform
);


document.getElementById(
    "rotate"
).addEventListener(
    "input",
    updateTransform
);


/* ======================================
   السطوع والتباين والتشبع
====================================== */

function updateColor() {

    const brightness =
        document.getElementById(
            "brightness"
        ).value;

    const contrast =
        document.getElementById(
            "contrast"
        ).value;

    const saturation =
        document.getElementById(
            "saturation"
        ).value;

    let filter = `
        brightness(${brightness}%)
        contrast(${contrast}%)
        saturate(${saturation}%)
    `;

    video.style.filter =
        filter;
}


document.getElementById(
    "brightness"
).addEventListener(
    "input",
    updateColor
);


document.getElementById(
    "contrast"
).addEventListener(
    "input",
    updateColor
);


document.getElementById(
    "saturation"
).addEventListener(
    "input",
    updateColor
);


/* ======================================
   مستوى الصوت
====================================== */

document.getElementById(
    "volume"
).addEventListener(
    "input",
    function () {

        video.volume =
            Number(this.value) / 100;
    }
);


/* ======================================
   حذف
====================================== */

document.getElementById(
    "delete"
).onclick = () => {

    if (!selectedClip) {

        notify("حدد مقطعًا أولًا");

        return;
    }

    saveHistory();

    clips =
        clips.filter(
            clip =>
                clip.id !==
                selectedClip.id
        );

    selectedClip =
        clips[0] || null;

    renderAll();

    if (selectedClip) {

        loadClip(
            selectedClip
        );

    } else {

        video.pause();

        video.removeAttribute("src");

        video.style.display =
            "none";

        imagePreview.style.display =
            "none";

        emptyPreview.style.display =
            "flex";
    }

    notify("تم حذف المقطع");
};


/* ======================================
   تقسيم
====================================== */

document.getElementById(
    "split"
).onclick = () => {

    if (
        !selectedClip ||
        selectedClip.type !== "video"
    ) {

        notify(
            "حدد فيديو أولًا"
        );

        return;
    }

    const point =
        video.currentTime;

    if (
        point <= 0 ||
        point >= video.duration
    ) {

        notify(
            "ضع المؤشر داخل الفيديو"
        );

        return;
    }

    notify(
        "تم تحديد نقطة التقسيم"
    );
};


/* ======================================
   تراجع
====================================== */

document.getElementById(
    "undoBtn"
).onclick = () => {

    if (!history.length) {

        notify(
            "لا يوجد شيء للتراجع"
        );

        return;
    }

    const previous =
        JSON.parse(
            history.pop()
        );

    future.push(
        JSON.stringify(clips)
    );

    clips =
        previous.map(c => ({
            ...c
        }));

    selectedClip =
        clips[0] || null;

    renderAll();

    if (selectedClip) {
        loadClip(selectedClip);
    }

    notify("تم التراجع");
};


/* ======================================
   إعادة
====================================== */

document.getElementById(
    "redoBtn"
).onclick = () => {

    if (!future.length) {

        notify(
            "لا يوجد شيء للإعادة"
        );

        return;
    }

    const next =
        JSON.parse(
            future.pop()
        );

    history.push(
        JSON.stringify(clips)
    );

    clips =
        next.map(c => ({
            ...c
        }));

    selectedClip =
        clips[0] || null;

    renderAll();

    if (selectedClip) {
        loadClip(selectedClip);
    }

    notify("تمت الإعادة");
};


/* ======================================
   ملء الشاشة
====================================== */

document.getElementById(
    "fullscreenBtn"
).onclick = () => {

    const frame =
        document.getElementById(
            "videoFrame"
        );

    if (
        !document.fullscreenElement
    ) {

        frame.requestFullscreen();

    } else {

        document.exitFullscreen();
    }
};


/* ======================================
   معاينة
====================================== */

document.getElementById(
    "previewBtn"
).onclick = () => {

    if (!video.src) {

        notify(
            "أضف فيديو للمعاينة"
        );

        return;
    }

    if (video.paused) {

        video.play();

        notify(
            "بدأت المعاينة"
        );

    } else {

        video.pause();

        notify(
            "توقفت المعاينة"
        );
    }
};


/* ======================================
   التصدير
====================================== */

document.getElementById(
    "exportBtn"
).onclick = () => {

    if (!video.src) {

        notify(
            "أضف فيديو أولًا"
        );

        return;
    }

    notify(
        "محرك التصدير المتقدم سيكون في الإصدار التالي"
    );
};


/* ======================================
   تبديل اللوحات
====================================== */

const panelTitles = {

    media: "الوسائط",
    text: "النص",
    audio: "الصوت",
    effects: "المؤثرات",
    filters: "الفلاتر",
    transition: "الانتقالات",
    speed: "السرعة"
};


document
    .querySelectorAll(".tool")
    .forEach(tool => {

        tool.addEventListener(
            "click",
            () => {

                const panel =
                    tool.dataset.panel;

                if (!panel) return;

                document
                    .querySelectorAll(".tool")
                    .forEach(t =>
                        t.classList.remove(
                            "active"
                        )
                    );

                tool.classList.add(
                    "active"
                );

                document
                    .querySelectorAll(
                        ".panel-content"
                    )
                    .forEach(p =>
                        p.classList.remove(
                            "active"
                        )
                    );

                document
                    .getElementById(panel)
                    .classList.add(
                        "active"
                    );

                document.getElementById(
                    "panelTitle"
                ).textContent =
                    panelTitles[panel];
            }
        );
    });

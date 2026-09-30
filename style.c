* {
    box-sizing: border-box;
}

body {
    margin: 0;

    background:
        #080808;

    color: white;

    font-family:
        Arial,
        Tahoma,
        sans-serif;

    overflow: hidden;
}


/* =========================
   الشريط العلوي
========================= */

.topbar {

    height: 62px;

    display: flex;

    align-items: center;

    justify-content: space-between;

    padding: 0 20px;

    background: #111;

    border-bottom:
        1px solid #252525;
}


.brand {

    font-size: 20px;

    font-weight: 900;

    letter-spacing: 1px;
}


.brand span {

    font-size: 11px;

    color: #777;

    margin-right: 8px;

    font-weight: normal;
}


.top-actions {

    display: flex;

    gap: 8px;
}


.top-actions button {

    border: 0;

    background: #1c1c1c;

    color: #ddd;

    padding:
        9px 14px;

    border-radius: 6px;

    cursor: pointer;
}


.top-actions button:hover {

    background: #292929;
}


.top-actions .export {

    background:
        #e50914;

    color: white;

    font-weight: bold;
}


/* =========================
   المحرر
========================= */

.editor {

    height:
        calc(100vh - 62px);

    display: grid;

    grid-template-columns:
        82px 260px 1fr;
}


/* =========================
   الشريط الجانبي
========================= */

.sidebar {

    background:
        #0d0d0d;

    border-left:
        1px solid #242424;

    display: flex;

    flex-direction: column;

    align-items: center;

    padding-top: 12px;

    gap: 5px;
}


.tool {

    width: 72px;

    min-height: 65px;

    border: 0;

    background: transparent;

    color: #888;

    border-radius: 8px;

    cursor: pointer;

    display: flex;

    flex-direction: column;

    align-items: center;

    justify-content: center;

    gap: 5px;
}


.tool span {

    font-size: 20px;
}


.tool:hover,
.tool.active {

    background:
        #1d1d1d;

    color: white;
}


/* =========================
   لوحة الأدوات
========================= */

.panel {

    background:
        #111;

    border-left:
        1px solid #252525;

    overflow-y: auto;

    padding: 18px;
}


.panel-title {

    border-bottom:
        1px solid #272727;

    padding-bottom: 12px;

    margin-bottom: 18px;
}


.panel-title h2 {

    margin: 0;

    font-size: 18px;
}


.tool-panel {

    display: none;
}


.tool-panel.active {

    display: block;
}


.upload-box {

    min-height: 145px;

    border:
        1px dashed #444;

    border-radius: 10px;

    display: flex;

    flex-direction: column;

    align-items: center;

    justify-content: center;

    gap: 8px;

    cursor: pointer;

    margin-bottom: 12px;

    background:
        #151515;
}


.upload-box:hover {

    background:
        #1c1c1c;

    border-color:
        #777;
}


.upload-box.small {

    min-height: 100px;
}


.upload-box input {

    display: none;
}


.upload-icon {

    font-size: 28px;

    color: #aaa;
}


.upload-box small {

    color: #666;
}


/* =========================
   الأدوات
========================= */

.big-tool {

    width: 100%;

    padding: 14px;

    background:
        #252525;

    border: 0;

    color: white;

    border-radius: 7px;

    cursor: pointer;

    margin-bottom: 15px;
}


label {

    display: block;

    color: #aaa;

    font-size: 13px;

    margin:
        15px 0;
}


label input {

    display: block;

    width: 100%;

    margin-top: 8px;
}


.effect-btn,
.filter-btn,
.speed-btn,
.transition-btn {

    width: 100%;

    padding: 12px;

    margin-bottom: 7px;

    border:
        1px solid #2c2c2c;

    background:
        #191919;

    color: white;

    border-radius: 6px;

    cursor: pointer;
}


.effect-btn:hover,
.filter-btn:hover,
.speed-btn:hover,
.transition-btn:hover {

    background:
        #292929;
}


.transition-btn {

    text-align: right;
}


.transition-btn small {

    display: block;

    color: #777;

    margin-top: 3px;
}


/* =========================
   منطقة العمل
========================= */

.workspace {

    min-width: 0;

    display: flex;

    flex-direction: column;

    background:
        #0b0b0b;
}


.preview {

    flex: 1;

    min-height: 0;

    display: flex;

    align-items: center;

    justify-content: center;

    padding: 25px;
}


.video-stage {

    width: min(
        900px,
        90%
    );

    height: min(
        70vh,
        520px
    );

    background:
        #000;

    position: relative;

    overflow: hidden;

    border-radius: 5px;

    display: flex;

    align-items: center;

    justify-content: center;
}


.video-stage video {

    width: 100%;

    height: 100%;

    object-fit: contain;

    transition:
        filter .3s,
        transform .3s;
}


.text-overlay {

    position: absolute;

    top: 50%;

    left: 50%;

    transform:
        translate(-50%,-50%);

    font-weight: bold;

    font-size: 45px;

    text-align: center;

    pointer-events: none;

    text-shadow:
        2px 2px 5px black;
}


/* =========================
   المشغل
========================= */

.player-bar {

    display: flex;

    align-items: center;

    gap: 10px;

    padding:
        7px 18px;
}


.player-bar input {

    flex: 1;
}


.player-bar span {

    color: #777;

    font-size: 12px;
}


.controls {

    height: 52px;

    display: flex;

    justify-content: center;

    align-items: center;

    gap: 12px;

    border-top:
        1px solid #202020;
}


.controls button {

    width: 36px;

    height: 36px;

    border: 0;

    border-radius: 50%;

    background:
        #222;

    color: white;

    cursor: pointer;
}


.controls .play {

    background:
        #fff;

    color: #000;

    width: 42px;

    height: 42px;
}


/* =========================
   الخط الزمني
========================= */

.timeline {

    height: 210px;

    background:
        #101010;

    border-top:
        1px solid #272727;
}


.timeline-header {

    height: 48px;

    padding:
        0 15px;

    display: flex;

    align-items: center;

    justify-content: space-between;

    border-bottom:
        1px solid #242424;
}


.timeline-header button {

    background:
        #202020;

    border: 0;

    color: #ddd;

    padding:
        7px 11px;

    border-radius: 5px;

    cursor: pointer;

    margin-right: 5px;
}


.timeline-track {

    position: relative;

    height:
        calc(100% - 48px);

    padding: 25px 20px;

    overflow-x: auto;
}


.timeline-clip {

    height: 75px;

    min-width: 230px;

    width: 350px;

    background:
        #1e1e1e;

    border:
        2px solid transparent;

    border-radius: 6px;

    overflow: hidden;

    position: relative;

    cursor: pointer;
}


.timeline-clip.selected {

    border-color:
        #e50914;
}


.clip-preview {

    width: 100%;

    height: 100%;

    object-fit: cover;

    opacity: .75;
}


.clip-name {

    position: absolute;

    right: 10px;

    bottom: 8px;

    background:
        #000b;

    padding:
        4px 7px;

    border-radius: 3px;

    font-size: 11px;
}


.timeline-empty {

    height: 75px;

    border:
        1px dashed #333;

    border-radius: 6px;

    display: flex;

    align-items: center;

    justify-content: center;

    color: #555;
}


/* =========================
   الفلاتر
========================= */

.filter-cinema {

    filter:
        contrast(1.12)
        saturate(1.1)
        brightness(.9);
}


.filter-bw {

    filter:
        grayscale(1);
}


.filter-warm {

    filter:
        sepia(.25)
        saturate(1.2);
}


.filter-cool {

    filter:
        hue-rotate(15deg)
        saturate(.9);
}


/* =========================
   مؤثرات
========================= */

.effect-shake {

    animation:
        shake .12s infinite;
}


.effect-zoom {

    transform:
        scale(1.08);
}


.effect-blur {

    filter:
        blur(3px);
}


.effect-glitch {

    animation:
        glitch .15s infinite;
}


@keyframes shake {

    0% {
        transform: translate(0);
    }

    25% {
        transform: translate(4px,-3px);
    }

    50% {
        transform: translate(-4px,3px);
    }

    75% {
        transform: translate(3px,2px);
    }

    100% {
        transform: translate(0);
    }
}


@keyframes glitch {

    0% {
        transform:
            translate(0);
    }

    30% {
        transform:
            translate(-4px,2px);
    }

    60% {
        transform:
            translate(4px,-2px);
    }

    100% {
        transform:
            translate(0);
    }
}


/* =========================
   الرسالة
========================= */

#toast {

    position: fixed;

    bottom: 25px;

    left: 50%;

    transform:
        translate(-50%,30px);

    background:
        white;

    color:
        black;

    padding:
        11px 18px;

    border-radius:
        6px;

    opacity:
        0;

    transition:
        .25s;

    pointer-events:
        none;

    z-index:
        5000;
}


#toast.show {

    opacity:
        1;

    transform:
        translate(-50%,0);
}


/* =========================
   الجوال
========================= */

@media(max-width:800px) {

    body {
        overflow: auto;
    }


    .editor {

        height: auto;

        min-height:
            calc(100vh - 62px);

        grid-template-columns:
            65px 1fr;

        grid-template-rows:
            auto;
    }


    .sidebar {

        grid-row:
            1 / 3;

        position:
            sticky;

        top: 0;

        height:
            calc(100vh - 62px);
    }


    .panel {

        min-height:
            420px;

        border-bottom:
            1px solid #222;
    }


    .workspace {

        grid-column:
            2;
    }


    .preview {

        min-height:
            320px;
    }


    .video-stage {

        width: 95%;

        height: 300px;
    }


    .timeline {

        height: 180px;
    }


    .topbar {

        padding:
            0 10px;
    }


    .brand span {

        display: none;
    }


    .top-actions button {

        padding:
            7px 8px;

        font-size: 11px;
    }

}

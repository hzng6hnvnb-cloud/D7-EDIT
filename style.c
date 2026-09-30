:root {
    --bg: #050609;
    --glass: rgba(255,255,255,.055);
    --glass2: rgba(255,255,255,.085);
    --border: rgba(255,255,255,.10);
    --text: #f5f5f7;
    --muted: #85858d;
    --accent: #7c5cff;
    --accent2: #b36cff;
}

* {
    box-sizing: border-box;
}

html,
body {
    width: 100%;
    height: 100%;
    margin: 0;
}

body {
    background:
        radial-gradient(
            circle at 75% 10%,
            rgba(124,92,255,.15),
            transparent 30%
        ),
        radial-gradient(
            circle at 20% 80%,
            rgba(0,200,255,.08),
            transparent 30%
        ),
        #050609;

    color: var(--text);

    font-family:
        Arial,
        Tahoma,
        sans-serif;

    overflow: hidden;
}


/* ==============================
   الخلفية
============================== */

.background-glow {
    position: fixed;
    width: 500px;
    height: 500px;
    border-radius: 50%;
    filter: blur(130px);
    opacity: .13;
    pointer-events: none;
}

.glow-1 {
    background: #6d4aff;
    top: -300px;
    right: 25%;
}

.glow-2 {
    background: #00b7ff;
    bottom: -350px;
    left: 10%;
}


/* ==============================
   الزجاج
============================== */

.glass {
    background:
        linear-gradient(
            135deg,
            rgba(255,255,255,.075),
            rgba(255,255,255,.025)
        );

    border:
        1px solid var(--border);

    backdrop-filter:
        blur(28px)
        saturate(140%);

    -webkit-backdrop-filter:
        blur(28px)
        saturate(140%);

    box-shadow:
        0 20px 70px rgba(0,0,0,.35),
        inset 0 1px rgba(255,255,255,.05);
}


/* ==============================
   الشريط العلوي
============================== */

.topbar {
    height: 68px;

    margin: 10px;

    border-radius: 17px;

    display: flex;
    align-items: center;
    justify-content: space-between;

    padding: 0 17px;

    position: relative;
    z-index: 10;
}


.logo {
    display: flex;
    align-items: center;
    gap: 10px;
    min-width: 170px;
}


.logo-mark {
    width: 38px;
    height: 38px;

    display: grid;
    place-items: center;

    border-radius: 11px;

    background:
        linear-gradient(
            135deg,
            #8d72ff,
            #4b30bd
        );

    box-shadow:
        0 8px 25px rgba(124,92,255,.35);

    font-weight: 900;
    font-size: 20px;
}


.logo strong {
    display: block;
    font-size: 15px;
    letter-spacing: 2px;
}


.logo small {
    display: block;
    color: var(--muted);
    margin-top: 2px;
    font-size: 10px;
}


.project-name {
    color: #ddd;
    font-size: 13px;
}


.project-name span {
    color: #67dc91;
    margin-right: 8px;
    font-size: 11px;
}


.top-buttons {
    display: flex;
    gap: 7px;
    align-items: center;
}


.top-buttons button {
    border: 1px solid var(--border);
    background: rgba(255,255,255,.055);
    color: white;

    height: 38px;
    padding: 0 13px;

    border-radius: 9px;

    cursor: pointer;

    transition: .2s;
}


.top-buttons button:hover {
    background: rgba(255,255,255,.11);
}


.preview-btn {
    color: #ddd !important;
}


.export-btn {
    border: 0 !important;

    background:
        linear-gradient(
            135deg,
            #7b5cff,
            #a24cff
        ) !important;

    box-shadow:
        0 8px 25px rgba(124,92,255,.25);
}


/* ==============================
   التطبيق
============================== */

.app {
    height:
        calc(100vh - 88px);

    margin:
        0 10px 10px;

    display: grid;

    grid-template-columns:
        72px 245px minmax(400px,1fr) 245px;

    gap: 8px;
}


/* ==============================
   الأدوات
============================== */

.tools {
    border-radius: 17px;

    padding:
        8px 5px;

    display: flex;

    flex-direction: column;

    align-items: center;

    gap: 4px;
}


.tool {
    width: 60px;
    height: 58px;

    border: 0;

    background: transparent;

    color: #85858d;

    border-radius: 12px;

    cursor: pointer;

    display: flex;
    flex-direction: column;

    align-items: center;
    justify-content: center;

    gap: 5px;

    transition: .2s;
}


.tool span {
    font-size: 18px;
}


.tool small {
    font-size: 9px;
}


.tool:hover {
    color: white;
    background: rgba(255,255,255,.06);
}


.tool.active {
    color: white;

    background:
        linear-gradient(
            135deg,
            rgba(124,92,255,.30),
            rgba(124,92,255,.08)
        );

    box-shadow:
        inset 0 0 0 1px rgba(124,92,255,.25);
}


.tool-bottom {
    margin-top: auto;
}


/* ==============================
   اللوحة اليسار
============================== */

.left-panel {
    border-radius: 17px;
    overflow: hidden;
}


.panel-heading {
    height: 75px;

    padding:
        17px;

    border-bottom:
        1px solid var(--border);
}


.panel-heading h2 {
    margin: 0 0 5px;
    font-size: 17px;
}


.panel-heading span {
    color: var(--muted);
    font-size: 10px;
}


.panel-content {
    display: none;
    padding: 15px;
    overflow-y: auto;
    height:
        calc(100% - 75px);
}


.panel-content.active {
    display: block;
}


.panel-content::-webkit-scrollbar {
    width: 4px;
}


.panel-content::-webkit-scrollbar-thumb {
    background: #333;
    border-radius: 20px;
}


/* ==============================
   رفع الملفات
============================== */

.upload-card {
    min-height: 145px;

    border:
        1px dashed rgba(255,255,255,.18);

    background:
        rgba(255,255,255,.035);

    border-radius: 14px;

    display: flex;
    flex-direction: column;

    align-items: center;
    justify-content: center;

    gap: 8px;

    cursor: pointer;

    transition: .25s;

    margin-bottom: 10px;
}


.upload-card:hover {
    background:
        rgba(124,92,255,.09);

    border-color:
        rgba(124,92,255,.5);

    transform:
        translateY(-2px);
}


.upload-card input {
    display: none;
}


.upload-symbol {
    width: 44px;
    height: 44px;

    border-radius: 12px;

    display: grid;
    place-items: center;

    background:
        rgba(255,255,255,.07);

    font-size: 24px;

    color: #aaa;
}


.upload-card strong {
    font-size: 12px;
}


.upload-card span {
    font-size: 9px;
    color: #666;
}


.upload-card.compact {
    min-height: 85px;
    flex-direction: row;
    justify-content: flex-start;
    padding: 10px;
}


.upload-card.compact .upload-symbol {
    width: 35px;
    height: 35px;
}


.section-label {
    color: #666;
    font-size: 10px;
    margin:
        20px 0 9px;
}


/* ==============================
   الملفات
============================== */

.asset {
    height: 58px;

    display: flex;
    align-items: center;

    gap: 9px;

    padding: 6px;

    background:
        rgba(255,255,255,.035);

    border:
        1px solid transparent;

    border-radius: 9px;

    margin-bottom: 6px;

    cursor: pointer;
}


.asset:hover {
    border-color:
        rgba(255,255,255,.12);
}


.asset-thumb {
    width: 68px;
    height: 44px;

    border-radius: 6px;

    object-fit: cover;

    background: #000;
}


.asset-name {
    overflow: hidden;
    white-space: nowrap;
    text-overflow: ellipsis;

    font-size: 10px;
    color: #bbb;
}


/* ==============================
   التحكم
============================== */

.control {
    margin:
        16px 0;
}


.control label {
    display: block;
    color: #999;
    font-size: 10px;
    margin-bottom: 8px;
}


.control input[type="text"],
.control input[type="number"] {
    width: 100%;

    border:
        1px solid var(--border);

    background:
        rgba(0,0,0,.2);

    color: white;

    border-radius: 8px;

    padding: 10px;

    outline: none;
}


input[type="range"] {
    width: 100%;
    accent-color: var(--accent);
}


/* ==============================
   الأزرار
============================== */

.add-big {
    width: 100%;

    padding: 13px;

    border: 1px solid rgba(124,92,255,.3);

    background:
        rgba(124,92,255,.12);

    color: white;

    border-radius: 10px;

    cursor: pointer;
}


.text-presets {
    display: flex;
    gap: 5px;
}


.text-presets button {
    flex: 1;

    padding: 9px 3px;

    background:
        rgba(255,255,255,.05);

    color: #aaa;

    border: 1px solid var(--border);

    border-radius: 7px;

    font-size: 9px;
}


/* ==============================
   المؤثرات
============================== */

.effects-grid,
.filter-grid {
    display: grid;

    grid-template-columns:
        1fr 1fr;

    gap: 8px;
}


.effect-card {
    height: 92px;

    border: 1px solid var(--border);

    border-radius: 12px;

    background:
        linear-gradient(
            135deg,
            rgba(255,255,255,.06),
            rgba(255,255,255,.025)
        );

    color: white;

    cursor: pointer;

    transition: .2s;
}


.effect-card:hover {
    transform:
        translateY(-2px);

    border-color:
        rgba(124,92,255,.4);
}


.effect-card div {
    font-size: 27px;
    margin-bottom: 8px;
}


.effect-card span {
    font-size: 10px;
    color: #aaa;
}


/* ==============================
   الفلاتر
============================== */

.filter-card {
    border: 1px solid var(--border);

    background:
        rgba(255,255,255,.035);

    border-radius: 10px;

    padding: 5px;

    color: white;

    cursor: pointer;
}


.filter-card div {
    height: 65px;

    border-radius: 7px;

    background:
        linear-gradient(
            135deg,
            #777,
            #222
        );

    margin-bottom: 5px;
}


.filter-card span {
    font-size: 9px;
    color: #aaa;
}


.filter-card.cinema div {
    filter:
        contrast(1.25)
        saturate(.8)
        sepia(.2);
}


.filter-card.bw div {
    filter:
        grayscale(1);
}


.filter-card.warm div {
    filter:
        sepia(.45)
        saturate(1.25);
}


.filter-card.cool div {
    filter:
        hue-rotate(25deg);
}


.filter-card.vivid div {
    filter:
        saturate(1.8)
        contrast(1.15);
}


/* ==============================
   الانتقالات
============================== */

.transition-item {
    width: 100%;

    padding: 15px;

    margin-bottom: 8px;

    text-align: right;

    border:
        1px solid var(--border);

    background:
        rgba(255,255,255,.035);

    color: white;

    border-radius: 10px;

    cursor: pointer;
}


.transition-item strong {
    display: block;
    font-size: 12px;
    margin-bottom: 5px;
}


.transition-item span {
    color: #666;
    font-size: 9px;
}


/* ==============================
   السرعة
============================== */

.speed-title {
    color: #aaa;
    font-size: 11px;
    margin-bottom: 12px;
}


.speed-grid {
    display: grid;
    grid-template-columns: 1fr 1fr;
    gap: 7px;
}


.speed-grid button {
    padding: 12px;

    background:
        rgba(255,255,255,.045);

    color: white;

    border: 1px solid var(--border);

    border-radius: 8px;

    cursor: pointer;
}


/* ==============================
   منطقة العمل
============================== */

.workspace {
    min-width: 0;

    display: flex;
    flex-direction: column;

    overflow: hidden;
}


.workspace-top {
    height: 42px;

    display: flex;
    align-items: center;
    justify-content: space-between;

    padding: 0 10px;
}


.workspace-top button,
.resolution {
    border:
        1px solid var(--border);

    background:
        rgba(255,255,255,.045);

    color: #aaa;

    border-radius: 7px;

    padding: 6px 10px;

    font-size: 10px;
}


.workspace-title {
    font-size: 11px;
    color: #777;
}


/* ==============================
   شاشة الفيديو
============================== */

.preview-area {
    flex: 1;

    min-height: 0;

    display: flex;

    align-items: center;
    justify-content: center;

    padding: 5px;
}


.video-frame {
    width: min(900px, 94%);
    aspect-ratio: 16 / 9;

    background: #000;

    border:
        1px solid rgba(255,255,255,.1);

    border-radius: 8px;

    overflow: hidden;

    position: relative;

    box-shadow:
        0 30px 80px rgba(0,0,0,.55);
}


.video-frame video,
.video-frame img {
    position: absolute;

    inset: 0;

    width: 100%;
    height: 100%;

    object-fit: contain;

    display: none;
}


.empty-preview {
    position: absolute;

    inset: 0;

    display: flex;

    flex-direction: column;

    align-items: center;
    justify-content: center;

    color: #555;
}


.empty-icon {
    width: 58px;
    height: 58px;

    border-radius: 50%;

    display: grid;
    place-items: center;

    background:
        rgba(255,255,255,.05);

    color: #777;

    margin-bottom: 12px;
}


.empty-preview strong {
    font-size: 12px;
    color: #888;
}


.empty-preview span {
    font-size: 9px;
    margin-top: 5px;
}


.text-overlay {
    position: absolute;

    left: 50%;
    top: 50%;

    transform:
        translate(-50%,-50%);

    font-size: 48px;

    font-weight: 900;

    color: white;

    text-align: center;

    text-shadow:
        0 3px 15px #000;

    pointer-events: none;

    white-space: nowrap;
}


/* ==============================
   المشغل
============================== */

.player {
    display: flex;
    align-items: center;

    gap: 10px;

    padding:
        7px 20px;
}


.player input {
    flex: 1;
}


.player span {
    color: #666;
    font-size: 9px;
}


.player-controls {
    height: 48px;

    display: flex;
    align-items: center;
    justify-content: center;

    gap: 9px;
}


.player-controls button {
    width: 32px;
    height: 32px;

    border-radius: 50%;

    border: 1px solid var(--border);

    background:
        rgba(255,255,255,.045);

    color: #aaa;

    cursor: pointer;
}


.player-controls .main-play {
    width: 40px;
    height: 40px;

    background:
        white;

    color: black;

    border: 0;
}


/* ==============================
   الخصائص
============================== */

.properties {
    border-radius: 17px;
    overflow-y: auto;
}


.property-title {
    height: 75px;

    padding: 17px;

    border-bottom:
        1px solid var(--border);
}


.property-title strong {
    display: block;
    font-size: 15px;
}


.property-title span {
    color: #666;
    font-size: 9px;
}


.property-section {
    padding:
        17px;

    border-bottom:
        1px solid var(--border);
}


.property-heading {
    font-size: 11px;
    font-weight: bold;

    margin-bottom: 15px;
}


.two-columns {
    display: grid;
    grid-template-columns: 1fr 1fr;
    gap: 7px;
}


.two-columns span {
    display: block;
    color: #666;
    font-size: 8px;
    margin-bottom: 5px;
}


.two-columns input {
    width: 100%;

    background:
        rgba(0,0,0,.25);

    border:
        1px solid var(--border);

    color: white;

    padding: 8px;

    border-radius: 7px;
}


/* ==============================
   الخط الزمني
============================== */

.timeline {
    height: 180px;

    border-radius: 14px;

    margin:
        5px 0 0;

    overflow: hidden;
}


.timeline-head {
    height: 43px;

    padding:
        0 12px;

    display: flex;
    align-items: center;
    justify-content: space-between;

    border-bottom:
        1px solid var(--border);
}


.timeline-head strong {
    font-size: 11px;
}


.timeline-head span {
    color: #555;
    font-size: 9px;
    margin-right: 8px;
}


.timeline-actions button {
    border:
        1px solid var(--border);

    background:
        rgba(255,255,255,.04);

    color: #aaa;

    border-radius: 6px;

    padding:
        5px 8px;

    cursor: pointer;

    font-size: 9px;
}


.timeline-body {
    height:
        calc(100% - 43px);

    overflow-x: auto;

    padding: 20px 15px;
}


.timeline-ruler {
    display: flex;

    justify-content: space-between;

    min-width: 650px;

    color: #444;

    font-size: 8px;

    margin-bottom: 9px;
}


.track {
    min-width: 650px;

    min-height: 67px;

    display: flex;

    gap: 5px;

    align-items: center;
}


.timeline-clip {
    height: 62px;

    min-width: 150px;

    width: 220px;

    position: relative;

    overflow: hidden;

    border:
        1px solid rgba(255,255,255,.1);

    border-radius: 7px;

    background:
        #151515;

    cursor: pointer;

    transition: .2s;
}


.timeline-clip.selected {
    border:
        2px solid var(--accent);

    box-shadow:
        0 0 20px rgba(124,92,255,.18);
}


.timeline-clip img,
.timeline-clip video {
    width: 100%;
    height: 100%;

    object-fit: cover;

    opacity: .6;
}


.timeline-name {
    position: absolute;

    right: 7px;
    bottom: 5px;

    padding:
        3px 6px;

    background:
        rgba(0,0,0,.65);

    border-radius: 4px;

    font-size: 8px;
}


/* ==============================
   المؤثرات
============================== */

.effect-shake {
    animation:
        shake .12s infinite;
}


.effect-zoom {
    animation:
        zoomEffect 2s infinite alternate;
}


.effect-blur {
    filter:
        blur(4px);
}


.effect-glitch {
    animation:
        glitch .16s infinite;
}


.effect-pulse {
    animation:
        pulse 1s infinite alternate;
}


@keyframes shake {

    0% {
        transform: translate(0);
    }

    25% {
        transform: translate(3px,-2px);
    }

    50% {
        transform: translate(-3px,2px);
    }

    75% {
        transform: translate(2px,2px);
    }

    100% {
        transform: translate(0);
    }
}


@keyframes zoomEffect {

    from {
        transform: scale(1);
    }

    to {
        transform: scale(1.08);
    }
}


@keyframes glitch {

    0% {
        transform: translate(0);
    }

    30% {
        transform: translate(-4px,1px);
    }

    60% {
        transform: translate(4px,-1px);
    }

    100% {
        transform: translate(0);
    }
}


@keyframes pulse {

    from {
        opacity: .75;
    }

    to {
        opacity: 1;
    }
}


/* ==============================
   الرسائل
============================== */

#toast {
    position: fixed;

    bottom: 25px;
    left: 50%;

    transform:
        translate(-50%,30px);

    background:
        rgba(25,25,30,.9);

    border:
        1px solid rgba(255,255,255,.12);

    backdrop-filter:
        blur(20px);

    color: white;

    padding:
        11px 18px;

    border-radius: 9px;

    font-size: 11px;

    opacity: 0;

    pointer-events: none;

    transition: .25s;

    z-index: 999;
}


#toast.show {
    opacity: 1;

    transform:
        translate(-50%,0);
}


/* ==============================
   الجوال
============================== */

@media(max-width:1050px) {

    .app {
        grid-template-columns:
            65px 220px minmax(350px,1fr);

    }

    .properties {
        display: none;
    }

}


@media(max-width:750px) {

    body {
        overflow: auto;
    }

    .topbar {
        margin: 5px;
    }

    .project-name {
        display: none;
    }

    .app {
        height: auto;
        min-height: calc(100vh - 78px);

        grid-template-columns:
            58px 1fr;
    }

    .left-panel {
        min-height: 400px;
    }

    .workspace {
        grid-column: 2;
    }

    .timeline {
        height: 160px;
    }

    .top-buttons button {
        padding: 0 8px;
    }

    .preview-area {
        min-height: 300px;
    }

}

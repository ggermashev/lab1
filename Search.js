
var srch = document.querySelector('#search');
var btn = document.querySelector('.btn');

btn.onclick = function () {
    if (srch.value == 'torrent') {
        window.location.href = "Download.html";
    }

    if (srch.value == 'music') {
        window.location.href = "Music.html";
    }
}





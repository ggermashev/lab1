function message( text, string) {
    var html = document.querySelector('html');

    var panel = document.createElement('div');
    panel.setAttribute('class', 'msgBox');
    html.appendChild(panel);

    var msg = document.createElement('p');
    msg.textContent = text;
    panel.appendChild(msg);
    panel.style.background = 'url(' + string + ')' + 'no-repeat';
    panel.style.backgroundSize = '300px 500px';
    var cls = document.createElement('div');
    cls.setAttribute('class', 'close');
    panel.appendChild(cls);
    cls.style.backgroundColor = 'red';
    cls.textContent = 'X';

    cls.onclick = function () {
        html.lastElementChild.remove();
    }

}

message('Поробуй найти музыку', 'images/dog.png');


var srch = document.querySelector('#search');
var btn = document.querySelector('.btn');

btn.onclick = function () {
    if (srch.value == 'music') {
        window.location.href = "Music.html";
    }
}





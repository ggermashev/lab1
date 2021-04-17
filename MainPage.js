function message( text, string) {
var html = document.querySelector('html');

var panel = document.createElement('div');
panel.setAttribute('class', 'msgBox');
html.appendChild(panel);

var msg = document.createElement('p');
msg.textContent = text;
panel.appendChild(msg);
    panel.style.background = 'url(' + string + ')' + 'no-repeat';
    panel.style.backgroundSize = 'cover';
var cls = document.createElement('div');
cls.setAttribute('class', 'close');
panel.appendChild(cls);
cls.style.backgroundColor = 'red';
cls.textContent = 'close';


cls.onclick = function () {
    html.lastElementChild.remove();
}

}

message('hello', 'images/Desktop.png');


var brause = document.querySelector('.div1');
brause.onclick = function () {
    window.location.href = "Search.html";
}

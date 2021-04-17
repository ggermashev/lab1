function message(text, string) {
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

message('smth', 'images/dog.png');

var div1 = document.querySelector('.div1');
div1.onclick = function() {
    window.location.href = "Desktop.html";
}

var div2 = document.querySelector('.div2');
div2.onclick = function () {
    window.location.href = "Desktop.html";
}

var div3 = document.querySelector('.div3');
div3.onclick = function () {
    window.location.href = "Desktop.html";
}

var div4 = document.querySelector('.div4');
div4.onclick = function () {
    window.location.href = "Desktop.html";
}

var div5 = document.querySelector('.div5');
div5.onclick = function () {
    window.location.href = "Desktop.html";
}

var div6 = document.querySelector('.div6');
div6.onclick = function () {
    window.location.href = "Desktop.html";
}

var div7 = document.querySelector('.div7');
div7.onclick = function () {
    window.location.href = "Desktop.html";
}
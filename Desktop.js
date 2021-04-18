function message( text, string) {
    var html = document.querySelector('html');

    var panel = document.createElement('div1');
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

message('smth', 'images/dog.png');

var folder = document.querySelector('.folder');
folder.onclick = function () {
    html.lastElementChild.remove();
    message('smth', 'images/dog2.png')
    var html = document.querySelector('html');

    html=

    var alert = document.createElement('div');
    panel.setAttribute('class', 'alert');
    html.appendChild(alert);

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
} 

var brause = document.querySelector('.brouse');
brause.onclick = function () {
    window.location.href = "Search.html";
}

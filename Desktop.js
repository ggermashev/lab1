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

message('smth', 'images/dog.png');

var folder = document.querySelector('.folder');

var alrt;
var flag = 0;
folder.onclick = function () {

    var dsk = document.querySelector('.Desktop1');
    var html = document.querySelector('html');
    if (html.lastChild.nodeName === 'DIV') {
        html.lastChild.remove();
    }
    message('smth', 'images/dog2.png')


    alrt = document.querySelector('.error');
    alrt.setAttribute('src', 'images/alert.png');
    
    if (flag == 0) {
        alrt.removeAttribute('hidden','hidden');
        flag = 1;
    }
    

    alrt.onclick = function () {
        alrt.setAttribute('hidden', 'hidden');
        flag = 0;
    }
}
    
var brause = document.querySelector('.brouse');
brause.onclick = function () {
    window.location.href = "Search.html";
}

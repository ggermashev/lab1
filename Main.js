/*
var myButton = document.querySelector('.name');
var myHeading = document.querySelector('h1');

function setUserName() {
    var myName = prompt('Please enter your name.');
    localStorage.setItem('name', myName);
    myHeading.textContent = 'Mozilla is cool, ' + myName;
}

if (!localStorage.getItem('name')) {
    setUserName();
} else {
    var storedName = localStorage.getItem('name');
    myHeading.textContent = 'Mozilla is cool, ' + storedName;
}
*/

class accaunt {
    constructor(name, password) {
        this.login = name
        this.password = password
        this.result = null;
    }
}

class stats {
    constructor() {
        this.hp = 100;
        this.gold = 1000;
        this.bored = 0;
    }
}

let acc = [];
if (JSON.parse(localStorage.getItem(1))) {
    acc = JSON.parse(localStorage.getItem(1));
} 

let yours;

if (confirm("Do you have accaunt?")) {
    var log = prompt("input your login");
    for (var i = 0; i < acc.length; i++) {
        if (acc[i].login == log) {
            if (prompt('input your password') == acc[i].password ) {
                yours = acc[i];
                alert('ura');
                window.location.href = "MainPage.html";;
            }
        }
    }
} else {
    var elem = new accaunt(prompt("input your login"), prompt("input your password"));
    for (var i = 0; i < acc.length; i++) {
        if (acc[i].login == elem.login) {
            elem.login = prompt('input another login');
        }
    }
    acc.push(elem);
    alert(elem.login);
    localStorage.setItem(1, JSON.stringify(acc));
    alert('registration was successful, input your login')
    var log = prompt("input your login");
    for (var i = 0; i < acc.length; i++) {
        if (acc[i].login == log) {
            if (prompt('input your password') == acc[i].password) {
                yours = acc[i];
                window.location.href = "MainPage.html";
            }
        }
    }
}


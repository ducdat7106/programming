// Your web app's Firebase configuration
const firebaseConfig1 = {
    apiKey: "AIzaSyCeFg0Vnj6TXU-j4VvL-BhwVFkj8negsLE",
    authDomain: "tt-iot-utc.firebaseapp.com",
    databaseURL: "https://tt-iot-utc-default-rtdb.firebaseio.com",
    projectId: "tt-iot-utc",
    storageBucket: "tt-iot-utc.appspot.com",
    messagingSenderId: "457897367163",
    appId: "1:457897367163:web:0ba514c3f54782499fb4de"
};

firebase.initializeApp(firebaseConfig1);
firebase.analytics();

var my_database = firebase.database();


function set_data(path, username, email, password) {
    my_database.ref(path).set({
        username: username,
        email: email,
        password: password
    })
}


function clear_notification_error_password() {
    document.getElementById('pass').innerHTML = '';
    document.getElementById('pass_repeat').innerHTML = '';
}


function password_check(pass, pass_repeat) {
    var pass_true = 1;

    if (pass.length < 8) {
        document.getElementById('pass').innerHTML = 'Length password less than 8';
        document.getElementById('password_repeat').value = "";
        document.getElementById('password').value = "";
        return pass_true = 0;
    }

    if (pass.localeCompare(pass_repeat)) {
        clear_notification_error_password();

        if (pass_repeat.localeCompare('') == 0)
            document.getElementById('pass_repeat').innerHTML = 'Password repeat no empty';
        else {
            document.getElementById('pass_repeat').innerHTML = 'Password repeat different password!!!';
            document.getElementById('password_repeat').value = "";
        }

        return pass_true = 0;
    }

    clear_notification_error_password();

    return pass_true = 1;
}

function clear_notification_error_user_name() {
    document.getElementById('user_name').innerHTML = '';
}

function username_check(username) {
    var user_true = 1;

    if (username.localeCompare('') == 0) {
        document.getElementById('user_name').innerHTML = 'User name not empty';
        document.getElementById('username').value = '';
        return user_true = 0;
    }

    if (username.length < 6) {
        document.getElementById('user_name').innerHTML = 'User name not less than 6 character';

        return user_true = 0;
    }
    clear_notification_error_user_name();
    return user_true;
}

function clear_notification_error_email() {
    document.getElementById('gmail').innerHTML = '';
}


function sign_up_btn() {
    window.location.href = "./../login/login_index.html";
}

function get_pass() {
    return document.getElementById('password').value;
}

function get_pass_repeat() {
    return document.getElementById('password_repeat').value;
}

function get_username() {
    return document.getElementById("username").value;
}

function get_email() {
    return document.getElementById("email").value;
}

function information_user_signup(name, email, password) {
    let result = name.concat("\n", email, "\n", password);
    alert(result);
}


document.getElementById("signup_btn").onclick = function () {
    var username = get_username();
    var email = get_email();
    var pass = get_pass();
    var pass_repeat = get_pass_repeat();

    var test_pass = password_check(pass, pass_repeat);
    var test_user_name = username_check(username);


    if (test_pass == 1 && test_user_name == 1) {
        set_data('fix_error1',username, email, pass);

        information_user_signup(username, email, pass);
        setTimeout(sign_up_btn, 3000);

        return;
    }

    alert("Sign up fail!");
    return;
}

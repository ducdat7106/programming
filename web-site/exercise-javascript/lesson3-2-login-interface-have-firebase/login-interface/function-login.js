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

function set() {
    var email = "nhiennhienbn1@gmail.com";
    var password = 1234567;

    // var username = document.getElementById('username').value
    // var username = "ducdat";
    var username = 'dung';

    my_database.ref('infor_login/' + username).set({
        email: email,
        password: password
    });
}

function get() {
    var username = '';
    var data;
    var user_ref = my_database.ref('infor_login/' + username);

    user_ref.on('value', function (snapshot) {
        data = snapshot.val();
        console.log(data.email);
        console.log(data.password);
    });
}

function update() {
    var username = '';
    var gmail = 'ducdatn7@gmail.com';
    var password = 'iloveyou1';

    var update = {
        email: gmail,
        password: password
    }

    my_database.ref('infor_login/' + username).update(update)

    console.log('mail ' + gmail);
    console.log('password ' + password);

}

function remove() {
    var username = '';
    my_database.ref('infor_login/' + username).remove()
    console.log("deleted");
}
//==============================================================================================================
function set_data(path, username, gmail, password) {
    my_database.ref(path).set({
        username: username,
        email: gmail,
        password: password
    })
}
//==========================///=============================///===========================///=========

function path_login_successful() {
    window.location.href = "./../result-login-successful/index-successful-login.html";
    alert("Login successfully. Please continue.");
}

function path_login_error() {
    window.location.href = "./../result-error-login/index-error-login.html";
    alert("Login failed. You need login again!")
}

function check_name_and_pass(username_on_firebase, password_on_firebase) {
    var return_true = 1;
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;

    if (password.length < 8)
        return return_true = 0;

    if (username.localeCompare(username_on_firebase) != 0)
        return return_true = 0;

    if (password.localeCompare(password_on_firebase) != 0)
        return return_true = 0;

    return return_true = 1;
}

function submit_login(check_information) {
    if (check_information != 0) {
        path_login_successful();
        return;
    }
    path_login_error();
}

function get_data(path) {
    var user_ref = my_database.ref(path);
    user_ref.on('value', function (snapshot) {
        data = snapshot.val();

        console.log(data.email);
        console.log(data.password);
        console.log(data.username);

        var contain = check_name_and_pass(data.username, data.password);
        submit_login(contain);    
    });
}

document.getElementById("submit_login").onclick = function () {
    get_data('fix_error');
}
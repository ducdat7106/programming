function get_value_sign_up_form() {
    var name = document.getElementById("username").value;
    var email = document.getElementById("email").value;
    var password = document.getElementById("password").value;
    var password_repeat = document.getElementById("password_repeat").value;

   


    
    let result = name.concat(" ", email, " ", password, " ", password_repeat);
    alert(result);
}

function cancel_sign_up_form() {
    window.location.href = "https://www.google.com/";
}

document.getElementById("cancel_btn").onclick = function () {
    cancel_sign_up_form();
}

function reset_sign_up_form() {
    document.getElementById("inputs").reset();
}

document.getElementById("reset_btn").onclick = function () {
    reset_sign_up_form();
}

function sign_up_form() {
    window.location.href = "./../login/login_index.html";
}

document.getElementById("signup_btn").onclick = function () {
    get_value_sign_up_form();

    sign_up_form();
}
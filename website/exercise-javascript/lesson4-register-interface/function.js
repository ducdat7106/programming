function not_display_form_sign_up() {
    document.getElementById("id_01").style.display = "none"
}

not_display_form_sign_up();

// function handle even 1
function display_form_sign_up() {
    document.getElementById("start_form").style.display = "none";
    document.getElementById("id_01").style.display = "block";
}

document.getElementById("logo_sign_up").onclick = function () {
    display_form_sign_up();
}


// button cancel
function quit_sign_up() {
    document.getElementById("start_form").style.display = "block"
    document.getElementById("id_01").style.display = "none";
}

document.getElementById("cancel_btn").onclick = function () {
    quit_sign_up();
}


// button sign up 
function sign_up_successful() {
    window.location.href = "sign_up_successful.html"
}

function display_result() {
    var email = document.getElementById("email_id").value;
    var user = document.getElementById("username_id").value;
    var pass = 14; //document.getElementById("password_id").value;
    var pass_repeat = document.getElementById("password_repeat_id").value;

    alert("Hello\nHow are you?");
    alert(email)
    alert("Good Luck");

}

document.getElementById("signup_btn").onclick = function () {
    display_result();

    // sign_up_successful();
}

document.alert("password: ");
document.alert(pass);
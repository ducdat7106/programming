function clear_notification_error_password() {
    document.getElementById('pass').innerHTML = '';
    document.getElementById('pass_repeat').innerHTML = '';
}

function reset_sign_up_form() {
    clear_notification_error_password();
    document.getElementById("inputs").reset();
}

document.getElementById("reset_btn").onclick = function () {
    reset_sign_up_form();
}
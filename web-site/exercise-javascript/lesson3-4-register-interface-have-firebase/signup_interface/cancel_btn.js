function cancel_sign_up_form() {
    window.location.href = "https://www.google.com/";
}

document.getElementById("cancel_btn").onclick = function () {
    cancel_sign_up_form();
}
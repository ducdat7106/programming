function submit_login_interface() {
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;

    if (username == "dat" && password == "0") {
        window.location.href = "./../result-login-successful/index-successful-login.html";

        alert("Login successfully. Please continue.");
    } else {
        window.location.href = "./../result-error-login/index-error-login.html";

        alert("Login failed. You need login again!")
    }
}

document.getElementById("submit_login").onclick = function () {
    submit_login_interface();
}
function validate() {

    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;

    if (username == "dat" && password == "0") {

        // Redirecting to other page.
        window.location.href = "login_successful.html";

        alert("Login successfully.Please continue.");

    } else {

        // Redirecting to other page.
        window.location.href = "login_error.html";

        alert("Login failed. You need login again!")
    }
}
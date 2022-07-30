function login_again() {
    window.location.href = "./../login-interface/index-login.html";
    alert("Login again.")
}

document.getElementById("login_again").onclick = function()
{
    login_again();
}

function quit_web() {
    window.location.href = "https://www.google.com.vn";
    alert("Exit website.")
}

document.getElementById("exit").onclick = function()
{
    quit_web();
}
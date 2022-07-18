function validate() 
{
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;

    if (username == "dat" && password == "0") {
        
        location.href = "fix.html";
        // location.href = "https://www.w3schools.com";

        alert("Login successfully.Please continue.");

        // return false;
        // notification


    } else {

        // Redirecting to other page.
        window.location.href = "index.html";
        // window.location.href = "fix.html";

        // return false;
        // notification
        //  alert("Login successfully.Please continue.");

        alert("Login failed. You need login again!")
    }
}
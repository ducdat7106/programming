//a mouse click into image, image change 
//lamp turn off or lamp turn on
function changeColor()
{
    if( document.getElementById("image").src.endsWith("ledOff.png") )
        document.getElementById("image").src = "./image/ledOn.png";
    else
        document.getElementById("image").src = "./image/ledOff.png";
}

// press button change state lamp
function OnIntoOff() {
    document.getElementById("img_1").src = "./image/ledOff.png";
}

function OffIntoOn() {
    document.getElementById("img_1").src = "./image/ledOn.png";
}

// display variable
function changeTemprature() {
    var temp =806;
    document.getElementById("Temp").innerHTML = temp;
}

changeTemprature();

//turn on or turn off lamp with temprature
// var tempratureChange=100;
function imgChangeTemprature() {
    var temp1 = 50;
    if(temp1<100)
        document.getElementById("img_1").src = "./image/ledOff.png";
    else
        document.getElementById("img_1").src = "./image/ledOn.png";
}

imgChangeTemprature();
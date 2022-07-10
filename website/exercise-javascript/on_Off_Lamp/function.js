/*
    A mouse click into image, image change 
    turn off or turn on lamp.
*/
function changeColor() {
  if (document.getElementById("image").src.endsWith("ledOff.png"))
    document.getElementById("image").src = "./image/ledOn.png";
  else document.getElementById("image").src = "./image/ledOff.png";
}

// press button change state lamp
function OnIntoOff() {
  document.getElementById("img_1").src = "./image/ledOff.png";
}

function OffIntoOn() {
  document.getElementById("img_1").src = "./image/ledOn.png";
}

// display variable
function changeTemperature() {
  var temp = 804;
  document.getElementById("Temp").innerHTML = temp;
}

changeTemperature();

/*
    Turn on or turn off lamp with temprature
*/
function imgChangeTemperature() {
  var temp1 = 50;

  if (temp1 < 100) 
    document.getElementById("img_1").src = "./image/ledOff.png";
  else 
    document.getElementById("img_1").src = "./image/ledOn.png";
}

imgChangeTemperature();

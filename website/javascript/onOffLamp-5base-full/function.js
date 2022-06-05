  // Import the functions you need from the SDKs you need
  // import { initializeApp } from "https://www.gstatic.com/firebasejs/9.8.1/firebase-app.js";
  // TODO: Add SDKs for Firebase products that you want to use
  // https://firebase.google.com/docs/web/setup#available-libraries

  // Your web app's Firebase configuration
  const firebaseConfig = {
    apiKey: "AIzaSyCeFg0Vnj6TXU-j4VvL-BhwVFkj8negsLE",
    authDomain: "tt-iot-utc.firebaseapp.com",
    databaseURL: "https://tt-iot-utc-default-rtdb.firebaseio.com",
    projectId: "tt-iot-utc",
    storageBucket: "tt-iot-utc.appspot.com",
    messagingSenderId: "457897367163",
    appId: "1:457897367163:web:0ba514c3f54782499fb4de"
  };

  // Initialize Firebase
  // const app = initializeApp(firebaseConfig);

   // Initialize Firebase
   firebase.initializeApp(firebaseConfig);
   firebase.analytics();

   var mydatabase = firebase.database();

   var tempCo;
   var tempDust;
   var tempSound;
   var safe = 'An toàn';
   var danger = 'Nguy hiểm';


// get temp from 5base (auto update when data change)
mydatabase.ref("/Node1/co").on("value", function(snapshot){
  if(snapshot.exists())
  {
    tempCo = snapshot.val();
    document.getElementById("co").innerHTML = tempCo;
  }
  else
    console.log("No data available");
});

mydatabase.ref("/Node11/coSet").on("value", function(snapshot){
  if(snapshot.exists())
  {
    var temp = snapshot.val();
    if(tempCo>=temp)
    {
      document.getElementById("imgCo").src = "image/danger.jpg";
      document.getElementById("result").innerHTML = danger;
    }else{
      document.getElementById("imgCo").src = "image/safe.png";
      document.getElementById("result").innerHTML = safe;
  
      }  
    }
  else
    console.log("No data available");
  
});


mydatabase.ref("/Node1/dust").on("value", function(snapshot){
  if(snapshot.exists())
  {
    tempDust = snapshot.val();
    document.getElementById("dust").innerHTML = tempDust;
  }
  else
    console.log("No data available");
  
});

mydatabase.ref("/Node11/dustSet").on("value", function(snapshot){
  if(snapshot.exists())
  {
    var temp = snapshot.val();
    if(tempDust>=temp)
    {
      document.getElementById("imgDust").src = "./image/danger.jpg";
      document.getElementById("result").innerHTML = danger;
    }
    else
    {
      document.getElementById("imgDust").src = "./image/safe.png";
      document.getElementById("result").innerHTML = safe;
    }
  }
  else
    console.log("No data available");
  
});




mydatabase.ref("/Node1/sound").on("value", function(snapshot){
  if(snapshot.exists())
  {
    tempSound = snapshot.val();
    document.getElementById("sound").innerHTML = tempSound;
  }
  else
    console.log("No data available");
  
});

mydatabase.ref("/Node11/soundSet").on("value", function(snapshot){
  if(snapshot.exists())
  {
    var temp = snapshot.val();
    if(tempSound>=temp)
    {
      document.getElementById("imgSound").src = "./image/danger.jpg";
      document.getElementById("result").innerHTML = danger;
    }
    else
    {
      document.getElementById("imgSound").src = "./image/safe.png";
      document.getElementById("result").innerHTML = safe;
    }
  }
  else
    console.log("No data available");
});


//lam tuoi trang web
// let counter = 0;
// setInterval(() => {
//     document.querySelector('h1').innerText = counter;
//     counter++;
//     console.log(counter);
//     if(counter > 5) 
//       location.reload();
// }, 1000);


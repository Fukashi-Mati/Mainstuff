//security.fileuri.strict_origin_policy = false Firefox to work

function wczytajDaneTabeli() {
  var result = null;
  var xmlhttp = new XMLHttpRequest();
  xmlhttp.open("GET", "data.json", false);
  xmlhttp.send();
  if (xmlhttp.status == 200) {
      result = xmlhttp.responseText;
  }
  return result;
}
var data = wczytajDaneTabeli();
var mydata = JSON.parse(data);



var tablee = document.getElementById('mytable');
for(var i = 0; i < mydata.length; i++){
  var row = `<tr>
          <td>${mydata[i].nazwa}</td>
          <td>${mydata[i].typ}</td>
          <td>${mydata[i].limit}</td>
          <td>${mydata[i].cena1}</td>
          <td>${mydata[i].cena2}</td>
    </tr>`;

    tablee.innerHTML += row;
}

  
  
  //Nagłówek
  let naglowek = document.getElementById("naglowek");
  naglowek.style.fontSize = "100px";
  naglowek.style.fontWeight = "100";
  naglowek.style.color = "#003AAF";
  //Stopka
  let years = document.getElementById("year");
  years.innerHTML = new Date().getFullYear();
  class Firma 
  {
    constructor(fullnazwa, nip, ulica, kod_pocztowy,miasto, kraj){
      this.fullnazwa = fullnazwa;
      this.nip = nip;
      this.ulica = ulica;
      this.kod_pocztowy = kod_pocztowy;
      this.miasto = miasto;
      this.kraj = kraj;
    }
    writefullname(){
      return this.fullnazwa+ "<br/>";
    }
    writenip(){
      return "Nip: " + this.nip + "<br/>";
    }
    writeaddres(){
      return this.ulica + "<br/>" + this.kod_pocztowy + "<br/>" + this.miasto;
    }
    writekraj(){
      return this.kraj;
    }
  }
  const firma = new Firma("Ładowarkomania sp z.o.o", "2342525", "Łobuzowa 15", "69-420", "Zakraje", "Nibylandia");
  
  document.getElementById("fullnazwa").innerHTML = firma.writefullname();
  document.getElementById("nip").innerHTML = firma.writenip();
  document.getElementById("adres").innerHTML = firma.writeaddres();
  document.getElementById("kraj").innerHTML = firma.writekraj();
  
  //kolorki

  const napis = document.querySelector("#fullnazwa");
  napis.style.color = "black";

  function nasun(){
    napis.style.color = "red";
  }
  function odsun(){
    napis.style.color = "black";
  }

//   function init() {
//     loadJSON(function(response) {
//      // Parse JSON string into object
//        var actual_JSON = JSON.parse(response);
//        Console.log(actual_JSON);
//     });
//    }
  
//  function loadJSON(callback) {   

//   var xobj = new XMLHttpRequest();
//       xobj.overrideMimeType("application/json");
//       xobj.open('GET', 'data.json', true); // Replace 'my_data' with the path to your file
//       xobj.onreadystatechange = function () {
//         if (xobj.readyState == 4 && xobj.status == "200") {
//           // Required use of an anonymous callback as .open will NOT return a value but simply returns undefined in asynchronous mode
//           callback(xobj.responseText);
//         }
//   };
//   xobj.send(null);  
// }
  napis.addEventListener("mouseover", nasun);
  napis.addEventListener("mouseout", odsun);


  
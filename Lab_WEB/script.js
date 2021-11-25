//security.fileuri.strict_origin_policy = false Firefox to work
const languages = [
  ["pl", "Polski"],
  ["en", "English"]
];
function loadMenu(languages, language) {
  var xmlhttp = new XMLHttpRequest();
  xmlhttp.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      displayMenu(this);
      menuLanguageSelection(languages, this);
    }
  };
  switch (language) {
    case languages[0][0]:
      xmlhttp.open("GET", "menu-pl.xml", false);
      break;
    case languages[1][0]:
      xmlhttp.open("GET", "menu-en.xml", false);
      break;
    default:
      xmlhttp.open("GET", "menu-pl.xml", false);
  }
  xmlhttp.send();
}
function displayMenu(xml) {
  var x, i, xmlDoc, list;
  xmlDoc = xml.responseXML;
  list = '<ul>';
  x = xmlDoc.getElementsByTagName("item");
  for (i = 0; i < x.length; i++) {
    list += '<li><a href="' +
      x[i].getElementsByTagName("link")[0].childNodes[0].nodeValue + '">'
      + x[i].getElementsByTagName("name")[0].childNodes[0].nodeValue + '</a></li>';
  }
  list += '</ul>';
  document.getElementsByClassName("menu")[0].innerHTML = list;
}

function menuLanguageSelection(languages, xml) {
  var i, j, xmlDoc, lang, language, selectionList;
  xmlDoc = xml.responseXML;
  language = xmlDoc.getElementsByTagName("language")[0].childNodes[0].nodeValue;
  selectionList = 'Język: <select class="lang" id="lang">';
  for (i = 0; i < languages.length; i++) {
      selectionList += '<option value="' + languages[i][0] + '"';
      if (languages[i][1] == language) {
          selectionList += ' selected';
      }
      selectionList += '>' + languages[i][1] + '</option>';
  }
  selectionList += '</select>';
  document.getElementsByClassName("language")[0].innerHTML = selectionList;
  document.getElementById("lang").addEventListener("change", function () {
      lang = document.getElementById("lang").value;
      for (j = 0; j < languages.length; j++) {
          if (languages[j][0] == lang) {
              
          }
      }
      loadMenu(languages, lang);
      createCookie("language", lang,  Date.UTC(2021, 10, 29));
  });
}


let coooo = readCookie("language")
loadMenu(languages, coooo);
function readCookie(name) {
  let key = name + "=";
  let cookies = document.cookie.split(';');
  for (let i = 0; i < cookies.length; i++) {
    let cookie = cookies[i];
    while (cookie.charAt(0) === ' ') {
            cookie = cookie.substring(1, cookie.length);
        }
    if (cookie.indexOf(key) === 0) {
            return cookie.substring(key.length, cookie.length);
        }
  }
  return null;
}
function createCookie(key, value, date) {
  const expiration = new Date(date).toUTCString();
  console.log(expiration);
  const cookie = escape(key) + "=" + escape(value) + ";expires=" + expiration + ";";
  document.cookie = cookie;
  
}
//Nagłówek
let naglowek = document.getElementById("naglowek");
naglowek.style.fontSize = "100px";
naglowek.style.fontWeight = "100";
naglowek.style.color = "#003AAF";
//Stopka
let years = document.getElementById("year");
years.innerHTML = new Date().getFullYear();
class Firma {
  constructor(fullnazwa, nip, ulica, kod_pocztowy, miasto, kraj) {
    this.fullnazwa = fullnazwa;
    this.nip = nip;
    this.ulica = ulica;
    this.kod_pocztowy = kod_pocztowy;
    this.miasto = miasto;
    this.kraj = kraj;
  }
  writefullname() {
    return this.fullnazwa + "<br/>";
  }
  writenip() {
    return "Nip: " + this.nip + "<br/>";
  }
  writeaddres() {
    return this.ulica + "<br/>" + this.kod_pocztowy + "<br/>" + this.miasto;
  }
  writekraj() {
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

function nasun() {
  napis.style.color = "red";
}
function odsun() {
  napis.style.color = "black";
}

napis.addEventListener("mouseover", nasun);
napis.addEventListener("mouseout", odsun);



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
var opcje = document.getElementById('cars');
for (var i = 0; i < mydata.length; i++) {
  var row = `<tr>
          <td>${mydata[i].nazwa}</td>
          <td>${mydata[i].typ}</td>
          <td>${mydata[i].limit}</td>
          <td>${mydata[i].cena1}</td>
          <td>${mydata[i].cena2}</td>
    </tr>`;
  var optio = `<option value='${mydata[i].nazwa}'>${mydata[i].nazwa}</option>`;
  opcje.innerHTML += optio;
  tablee.innerHTML += row;
}

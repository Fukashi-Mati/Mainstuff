data = `[{
  "nazwa":"Żółwik",
  "typ":"Powolny",
  "limit": "250",
  "cena1":"50 zl",
  "cena2": "/ 45 zl"
},
{
  "nazwa":"Żółwik",
  "typ":"Powolny",
  "limit": "250",
  "cena1":"50 zl",
  "cena2": "/ 45 zl"
},
{
  "nazwa":"Żółwik",
  "typ":"Powolny",
  "limit": "250",
  "cena1":"50 zl",
  "cena2": "/ 45 zl"
}
]`;
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
  //nazwa spzpp, nip, ulica, kod poczt, miejscorwosc, kraj
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
  napis.addEventListener("mouseover", nasun);
  napis.addEventListener("mouseout", odsun);


  
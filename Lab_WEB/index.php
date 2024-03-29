<?php

require_once('secure.php');
?>

<!DOCTYPE html>
<html lang="pl" dir="ltr">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Mati</title>
    <link rel="stylesheet" href="style.css">
    <script src="script.js" defer></script>
    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
</head>

<body>
    <header>
        <div class="logo">
            <h2 id="naglowek">Ładowarkomania</h2>
            <svg width="100">
                <circle cs="50" cy="50" r="20" fill="blue"></circle>
            </svg>
        </div>
    </header>
    <div>
        <div class="language"></div>
        <div class="menu"></div>

        <main>
            Potrzeboujesz się naładowac? Odwiedź nas!
            <section class="strona aktywna" id="Strona Główna">
                <h2>Cennik</h2>
                <table class="tabela">
                    <thead>
                        <tr>
                            <th>Nazwa</th>
                            <th>Typ ładowania</th>
                            <th>Limit kWh</th>
                            <th colspan="2">Cena</th>
                        </tr>
                    </thead>
                    <tbody id="mytable"></tbody>
                </table>
            </section>
</br></br>
            <section class="strona" id="Kalkulator">
                <div id="kalk">
                    <form class='formu' method="POST">
                        <label for="typ">Typ:</label>
                        <select name="typ" id="cars">
                        </select>
                        <label for="liczba">Liczba miesięcy:</label>
                        <input type="text" name="liczba" /><br />
                        <button type="submit" name="pods" id="przycisk">Sprawdź cenę</button>
                    </form>
                </div>
            </section>
            <?php
            function saveMyFile($fileName, $data)
            {
                $file = @fopen($fileName, "a");
                if ($file == false) {
                    echo "Plik o takiej nazwie nie istnieje w tej lokalizacji?<br />";
                    $file = fopen($fileName, "a") or die("Nie można otworzyć pliku!");
                }
                fwrite($file, $data);
                fclose($file);
            }

            if (isset($_POST['pods'])) {
                $dane = file_get_contents("data.json");
                $dane = json_decode($dane);
                $pakiety = [];
                foreach($dane as $d)
                array_push($pakiety,get_object_vars($d));

                $typ = $_POST['typ'];
                $mno = $_POST['typ'];
                $mies = $_POST['liczba'];

                foreach($pakiety as $pakiet){
                    if($pakiet["nazwa"] == $mno){
                        $mno = (int)$pakiet["cena1"];
                    }
                }

                $wynik = $mno * $mies;
                $data = "<h2>To wyjdzie $wynik zł</h2> <h1> :/ </h1>";
                $log = "Klient obliczył miesięczny koszt $mno przez $mies miesięcy na kwotę $wynik zł ".PHP_EOL;
                echo $data;
                SaveMyFile("logi.txt", $log);
                $log2 = "$typ".PHP_EOL;
                saveMyFile("log.txt", $log2);
            }
            ?>
        <section class="strona" id="Tabelki">
        </br>
            <?php
            //session_start();
                if(!empty($_SESSION['username'])){
                    require_once('./Controller/Controller.php');
                    $Ctrl = new Controller();
                    $Ctrl->test();
                }

            ?>

            </section>
            <section class="strona" id="Galeria">
                <h2>Galeria</h2>
                <figure>
                    <img src="./stacja.jpg" width="1800" alt="stacja �adowania">
                    <figcaption>Ładna stacja i ładowanie samochodu</figcaption>
                </figure>
            </section>
            <section class="strona" id="Opinie">
                <h2>Opinie</h2>
                <div class="opinie">
                    <article class="komentarz">
                        <h4>Opinia 1</h4>
                        <p>Lorem ipsum, dolor sit amet consectetur adipisicing elit. Ad sapiente unde quibusdam temporibus aliquid corporis ut laudantium iusto ducimus eveniet nihil, blanditiis dolorum. Ipsam quia autem nostrum quas eveniet, in obcaecati sapiente maxime eius modi.</p>

                    </article>
                    <article class="komentarz">
                        <h4>Opinia 2</h4>
                        <p>Lorem ipsum dolor sit, amet consectetur adipisicing elit. Doloremque tempore, porro assumenda unde ut consectetur vitae deleniti, quasi molestias doloribus sint voluptatum dolore cupiditate maiores dolorem optio suscipit? Alias voluptas praesentium sequi ad, inventore obcaecati facilis neque. Exercitationem, omnis distinctio!</p>

                    </article>
                    <article class="komentarz">
                        <h4>Opinia 3</h4>
                        <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Sit odio, fuga incidunt doloribus nesciunt animi?</p>

                    </article>
                    <article class="komentarz">
                        <h4>Opinia 4</h4>
                        <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Delectus voluptatum alias quas. Ex quos omnis tempora error neque voluptas ipsam laborum eius dolor fugiat nulla quidem corrupti excepturi officiis corporis quae libero culpa, perspiciatis dolorum! Quae, eaque. Consequatur ipsam soluta suscipit quas praesentium aut fuga. Debitis ab aliquid molestiae eligendi optio accusamus, beatae corporis minima, modi quia at natus omnis nemo. Aliquid perferendis, libero voluptatem consequuntur recusandae unde et accusantium.</p>

                    </article>
                    <article class="komentarz">
                        <h4>Opinia 5</h4>
                        <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Iusto nobis quos, voluptas facilis consequatur, in dolorem adipisci aut perspiciatis vel dolore delectus aliquam quas consectetur eius dolorum enim numquam earum quisquam ipsum soluta eum eveniet quibusdam itaque. Nihil optio delectus officia unde provident vitae, eos, eum adipisci exercitationem ipsum, nesciunt architecto! Necessitatibus quibusdam eius eligendi iure quisquam quam id odit!</p>

                    </article>
                </div>
            </section>
            <section class="strona" id="Reklama">
                <h2>Reklama</h2>
                <video width="800" controls>
                    <source src="./microx.mov" type="video/mov">
                    Alternatywny tekst w razie
                    nieobsługiwania HTML Video.
                </video>
            </section>
            <section class="strona" id="Kontakt">
                <h2>Kontakt</h2>
                <form action="index.html" target="_self" method="get">
                    <table>
                        <tr>
                            <td><label for="fname">Imię:</label></td>
                            <td><input type="text" id="fname" name="fname" size="30" placeholder="Jan" /></td>
                        </tr>
                        <tr>
                            <td><label for="lname">Nazwisko:</label></td>
                            <td><input type="text" id="lname" name="lname" size="30" placeholder="Kowalski" /></td>
                        </tr>
                        <tr>
                            <td><label for="num">Telefon:</label></td>
                            <td><input type="number" id="num" name="num" size="9" placeholder="123456789" /></td>
                        </tr>
                        <tr>
                            <td><label for="wiad">Wiadomość</label></td>
                            <td><textarea rows="3" cols="30"></textarea></td>
                        </tr>
                        <tr>
                            <td><input type="submit" value="Wyślij"></td>
                        </tr>
                    </table>
                </form>
            </section>
        </main>
        
        <aside>
            <nav>
                <ul>
                    <li><a href="#top">Do góry</a></li>
                    <li><a href="#cennik">Cennik</a></li>
                    <li><a href="#galeria">Galeria</a></li>
                    <li><a href="#reklama">Reklama</a></li>
                    <li><a href="Kontakt">Kontakt</a></li>
                    <li><a href="login.php">Zaloguj</a></li>
                    <li><a href="logout.php">Wyloguj</a></li>
                </ul>
                <div>
                    <span id="fullnazwa"></span>
                    <span id="nip"></span>
                    <span id="adres"></span>
                    <span id="kraj"></span>
                </div>


            </nav>
        </aside>
    </div>
    <footer>
        <p>Copyright &copy; 2019 - <span id="year"></span> MI</p>
    </footer>
</body>
</html>
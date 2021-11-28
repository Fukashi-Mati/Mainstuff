<?php
class View{
    function displayTable($data) {
        echo('<table class="tabela">
                <thead><tr>
                    <th>Pakiet</th>
                    <th>Ilość</th>
                </tr></thead>
                <tbody>
        ');
        for($i = 0; $i < 3; $i++){
            echo('<tr><td>'.$data[$i][0].'</td>');
            echo('<td>'.$data[$i][1].'</td>');
            echo('</tr>');
        }
        echo('</tbody></table>');
        }

        function displayChart($data){
            echo('
            <script type="text/javascript">
                google.charts.load("current", {"packages":["corechart"]});
                google.charts.setOnLoadCallback(drawChart);
        
                function drawChart() {
                    var data = google.visualization.arrayToDataTable([
                        ["Pakiet", "Ilość"],
            ');
            for($i = 0; $i < 3; $i++){
                echo('["'.$data[$i][0].'", '.$data[$i][1].']');
                if ($i < sizeof($data)) echo(',');
            }
            echo('
        ]);
        var options = { title: "Ilość sprawdzonych pakietów", backgroundColor: "#FFFFFF" };
        var chart = new google.visualization.PieChart(document.getElementById("chart"));
        chart.draw(data, options);
            }
        </script>
        <div id="chart" style="margin:auto; width: 600px; height: 400px; margin-top: 0"></div>
');
        }
}

?>
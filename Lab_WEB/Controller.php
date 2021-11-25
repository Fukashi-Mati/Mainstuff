<?php
require_once("Model.php");
$model = new Model();
$model->readMyFile("log.txt");
$model->countArray();
echo $model->showArray();
?>
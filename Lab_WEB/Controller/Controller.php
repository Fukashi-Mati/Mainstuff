<?php
require_once("./Model/Model.php");
require_once("./View/View.php");
class Controller{

    private $model;
    private $view;

    function __construct(){
        $this->model = new Model();
        $this->view = new View();
    }

    function test(){
        $this->model->readMyFile("log.txt");
        $data = $this->model->getData();
        $this->view->displayTable($data);
        $this->view->displayChart($data);
    }

}
?>
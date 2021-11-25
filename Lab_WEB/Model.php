<?php
class Model{
    public $data = array();
    public $typy = array(array("Żółwik", "Zajac", "Nosorożec"), array(0,0,0));
    function readMyFile($fileName) {
        $file = @fopen($fileName, "r");
        if ($file) {
            $this->data = explode("\n", fread($file, filesize($fileName)));
        }
    }
    function countArray(){
        $i = 0;
        while($i <= count($this->data)){
            for($j = 0;$j < 3; $j++){
                if($this->data[$i] == $this->typy[0][$j]){
                    $this->typy[1][$j] = $this->typy[1][$j] + 1;
                }
            }
            $i++;
        }
    }
    function showArray(){
        return $this->typy[2][1];
    }

}
<?php
class Model{
    private $data = array(array("Żółwik", 0) , array("Zając", 0), array("Nosorożec", 0));

    function __construct(){

    }

    function readMyFile($fileName) {
        $file = @file_get_contents($fileName);
        $tab = $this->data;
        if ($file) {
            foreach (explode(PHP_EOL, $file) as $d){
                if(strlen($d)){
                    for($i = 0; $i < 3; $i++){
                        if($tab[$i][0] == $d){
                            $tab[$i][1] += 1;
                        }
                    
                    }
                }
            }

        }
        $this->data = $tab; 
    }


    function getData(){
        return $this->data;
    }

}
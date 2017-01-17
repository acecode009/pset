
<?php
    require("../includes/config.php");
    
    if($_SERVER["REQUEST_METHOD"]== "GET"){
        render("quote_form.php", ["title" => " Get Quote"]);
    }
    if($_SERVER["REQUEST_METHOD"]== "POST"){
        if(empty($_POST["symbol"]))
        {
            apologize("You must provide a symbol.");
        }
        
            $stock = lookup($_POST["symbol"]);
            if(!$stock)
            {
                apologize("Symbol not found");
            }
            else
            {
                render("../views/qprint.php", ["title" => " Get Quote","symbol"=>$stock["symbol"],"name"=>$stock["name"],"price"=>$stock["name"]]);                      
            }
            
            
        
        
    }

?>
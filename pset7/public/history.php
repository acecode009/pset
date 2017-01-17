<?php

    // configuration
    require("../includes/config.php"); 
    
    $cash = CS50::query("SELECT * FROM portfolio WHERE id = ?", $_SESSION["id"] );
    $data = CS50::query("SELECT * FROM history WHERE id = ?", $_SESSION["id"] );
    
    

    // render portfolio
    render("history_table.php", ["title" => "History","cash"=>$cash,"positions" => $data]);

?>

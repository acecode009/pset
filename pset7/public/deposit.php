<?php
    
    require("../includes/config.php");
   
    $users = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"] );
    
    if($_SERVER["REQUEST_METHOD"] == "POST"){
       
       if(empty($_POST["amount"]))
       {
           apologize("Please specify an amount.");
       }
       else
       {
           $transaction = 'DEPOSIT';
           CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?",$_POST["amount"],$_SESSION["id"]);
           //CS50::query("INSERT INTO history (id,transaction)",$_SESSION["id"], $transaction);
       
            render("../views/statement.php");
       }
           
    }
    else
    {
        render("deposit_form.php",["title"=>"Deposit"]);
    }

?>
<?php
        
        // configuration
    require("../includes/config.php");
    
    
   if($_SERVER["REQUEST_METHOD"] == "POST")
   {
        //query database
        $row = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"] );
        
        //variables
        $cash = $row[0]["cash"];
        $trade = 'BUY';
        $stock = lookup($_POST["symbol"]);
        $amount = $_POST["shares"];
        $price = $stock["price"];
        $cost = $amount * $price;
        
        //checkssss
        if(empty($_POST["symbol"]))
        {
            apologize("You must provide a symbol.");
        }
        else if(empty($_POST["shares"]))
        {
            apologize("You must provide amount of shares.");
        }
        
        else if(!preg_match("/^\d+$/", $_POST["shares"])){
            apologize("Invalid number of shares");
        }
        else if(!$stock)
        {
                apologize("Symbol not found");
        }
        else if(!$row)
        {
            apologize("Error acessing database");
        }
        else if ($cost < $cash)
        {               
            CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?",$cost,$_SESSION["id"]);
            CS50::query("INSERT INTO history (id, transaction, symbol, shares, price) VALUES (?, ?, ?, ?, ?)", $_SESSION["id"], $trade, $stock["symbol"], $amount, $stock["price"]);    
            CS50::query("INSERT INTO portfolio (id, symbol, shares) VALUES(?,?,?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)",$_SESSION["id"],$_POST["symbol"],$_POST["shares"]);
            redirect("/");
           
        }
            
            
        else{
                
                apologize("You cant afford that"); 
                
        }
          
   }
   else
   {
        render("buy_form.php",["title"=>"Buy Shares"]);
   }
?>
<?php

    // configuration
    require("../includes/config.php");
   
    $users = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"] );
   if($_SERVER["REQUEST_METHOD"] == "POST"){
       
       
       if(empty($_POST["symbol"]))
       {
           apologize("Please provide a symbol.");
       }
       else{
            //declare variables 
            $trade = 'SELL';
            $stock = lookup($_POST["symbol"]);
            $stock["symbol"] = strtoupper($_POST["symbol"]);
            
            //query database
            $shares = CS50::query("SELECT shares FROM portfolio where id = ? AND symbol = ?", $_SESSION["id"],$_POST["symbol"]);   
            $rows = CS50::query("SELECT * FROM portfolio WHERE id = ?", $_SESSION["id"]);
       
            $cost = $stock["price"] * $rows[0]["shares"];
            CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?",$cost,$_SESSION["id"]);
            CS50::query("DELETE FROM portfolio WHERE id = ? AND symbol = ?",$_SESSION["id"], $_POST["symbol"]);
            CS50::query("INSERT INTO history (id, transaction, symbol, shares, price) VALUES (?, ?, ?, ?, ?)", $_SESSION["id"], $trade, $stock["symbol"], $shares[0]["shares"], $stock["price"]);    
            
            redirect("/");
       }
   }
   else{
       $rows = CS50::query("SELECT * FROM portfolio WHERE id = ?", $_SESSION["id"]);
       
       $stocks = [];
       foreach($rows as $row)
       {
           $stock = $row["symbol"];
           
           $stocks[] = $stock;
       }
       render("sell_form.php",["title"=>"Sell Shares", "stocks"=>$stocks]);
   }
   
   
    

?>
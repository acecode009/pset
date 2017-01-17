<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <select name="symbol" class="form-control">
            <option value=''>Select Ticker</option>
                <?php
                    foreach($stocks as $symbol)
                    {
                        echo("<option value='$symbol'>".$symbol."</option>");
                    }
                    
                ?>
            </select>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit" value="SELL">
                <span aria-hidden="true" class="glyphicon glyphicon-usd"></span>
                SELL
            </button>
        </div>
    </fieldset>
</form>


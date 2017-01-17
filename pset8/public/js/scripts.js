/* global google */
/* global _ */
/**
 * scripts.js
 *
 * Computer Science 50
 * Problem Set 8
 *
 * Global JavaScript.
 */

// Google Map
var map;

// markers for map
var markers = [];


// info window
var info = new google.maps.InfoWindow();

// execute when the DOM is fully loaded
$(function() {

    // styles for map
    // https://developers.google.com/maps/documentation/javascript/styling
    var styles = [

        // hide Google's labels
        {
            featureType: "all",
            elementType: "labels",
            stylers: [
                {visibility: "on"}
            ]
        },

        // hide roads
        {
            featureType: "road",
            elementType: "geometry",
            stylers: [
                {visibility: "off"}
            ]
        }

    ];

    // options for map
    // https://developers.google.com/maps/documentation/javascript/reference#MapOptions
    var options = {
        center: {lat: 37.4236, lng: -122.1619}, // Stanford, California
        //disableDefaultUI: true,
        mapTypeId: google.maps.MapTypeId.ROADMAP,
        maxZoom: 20,
        panControl: true,
        styles: styles,
        zoom: 13,
        zoomControl: true,
        streetViewControl: true,
    };

    // get DOM node in which map will be instantiated
    var canvas = $("#map-canvas").get(0);

    // instantiate map
    map = new google.maps.Map(canvas, options);

    // configure UI once Google Map is idle (i.e., loaded)
    google.maps.event.addListenerOnce(map, "idle", configure);

});

/**
 * Adds marker for place to map.
 */
function addMarker(place)
{
    // TODO
    var myLatLng =new google.maps.LatLng(place['latitude'], place['longitude']);
    //console.log(place)
    var marker = new google.maps.Marker({
        map:map,
        position: myLatLng,
        draggable: true,
        animation: google.maps.Animation.DROP,
        title: place['place_name'] + "," + place['admin_name1']
       
        
    
});
markers.push(marker);
google.maps.event.addListener(marker, "click", function() {
        showInfo(marker);
        $.getJSON("articles.php", {geo: place.postal_code})
        .done(function(data, textStatus, jqXHR)
        {
            //if there is no news let the user know
            console.log($.getJSON("articles.php", {geo: place.postal_code}));
            if (data.length === 0)
            {
                showInfo(marker, "Slow News Day.");
            }
            //else display it in an unordered list
            else
            {
                var items = "<ul>";
                
               
                //insert link and title into ul
                for (var i = 0, len = data.length; i < len; i++)
                {
                   items+= "<li><a target='_blank' href="+ data[i].link + ">"+data[i].title + "</a></li>";
                }
                
                //end of the list
                items += "</ul>";
                
                //show news
                showInfo(marker, items);
            }
        });
    });
    
 

}

/**
 * Configures application.
 */
function configure()
{
    // update UI after map has been dragged
    google.maps.event.addListener(map, "dragend", function() {
        update();
    });

    // update UI after zoom level changes
    google.maps.event.addListener(map, "zoom_changed", function() {
        update();
    });

    // remove markers whilst dragging
    google.maps.event.addListener(map, "dragstart", function() {
        removeMarkers();
    });

    // configure typeahead
    // https://github.com/twitter/typeahead.js/blob/master/doc/jquery_typeahead.md
    $("#q").typeahead({
        autoselect: true,
        highlight: true,
        minLength: 1
    },
    {
        source: search,
        templates: {
            empty: "no places found yet",
            suggestion: _.template("<p><strong><%- place_name %></strong>, <%- admin_name1 %></p>")
        }
    });

    // re-center map after place is selected from drop-down
    $("#q").on("typeahead:selected", function(eventObject, suggestion, name) {

        // ensure coordinates are numbers
        var latitude = (_.isNumber(suggestion.latitude)) ? suggestion.latitude : parseFloat(suggestion.latitude);
        var longitude = (_.isNumber(suggestion.longitude)) ? suggestion.longitude : parseFloat(suggestion.longitude);

        // set map's center
        map.setCenter({lat: latitude, lng: longitude});

        // update UI
        update();
    });

    // hide info window when text box has focus
    $("#q").focus(function(eventData) {
       hideInfo();
    });

    // re-enable ctrl- and right-clicking (and thus Inspect Element) on Google Map
    // https://chrome.google.com/webstore/detail/allow-right-click/hompjdfbfmmmgflfjdlnkohcplmboaeo?hl=en
    document.addEventListener("contextmenu", function(event) {
        event.returnValue = true; 
        event.stopPropagation && event.stopPropagation(); 
        event.cancelBubble && event.cancelBubble();
    }, true);

    // update UI
    update();

    // give focus to text box
    $("#q").focus();
}

/**
 * Hides info window.
 */
function hideInfo()
{
    info.close();
}

/**
 * Removes markers from map.
 */
function removeMarkers()
{
    // TODO
    for(var i =0; i<markers.length;i++){
        markers[markers.length-1].setMap(null);
    }
    
}

/**
 * Searches database for typeahead's suggestions.
 */
function search(query, cb)
{
    // get places matching query (asynchronously)
    var parameters = {
        geo: query
    };
    $.getJSON("search.php", parameters)
    .done(function(data, textStatus, jqXHR) {

        // call typeahead's callback with search results (i.e., places)
        cb(data);
    })
    .fail(function(jqXHR, textStatus, errorThrown) {

        // log error to browser's console
        console.log(errorThrown.toString());
    });
}

/**
 * Shows info window at marker with content.
 */
function showInfo(marker, content)
{
    // start div
    var div = "<div id='info'>";
    if (typeof(content) === "undefined")
    {
        // http://www.ajaxload.info/
        div += "<img alt='loading' src='img/ajax-loader.gif'/>";
    }
    else
    {
        div += content;
    }

    // end div
    div += "</div>";

    // set info window's content
    info.setContent(div);

    // open info window (if not already open)
    info.open(map, marker);
}

/**
 * Updates UI's markers.
 */
function update() 
{
    // get map's bounds
    var bounds = map.getBounds();
    var ne = bounds.getNorthEast();
    var sw = bounds.getSouthWest();

    // get places within bounds (asynchronously)
    var parameters = {
        ne: ne.lat() + "," + ne.lng(),
        q: $("#q").val(),
        sw: sw.lat() + "," + sw.lng()
    };
    $.getJSON("update.php", parameters)
    .done(function(data, textStatus, jqXHR) {

        // remove old markers from map
        removeMarkers();

        // add new markers to map
        for (var i = 0; i < data.length; i++)
        {
            addMarker(data[i]);
        }
     })
     .fail(function(jqXHR, textStatus, errorThrown) {

         // log error to browser's console
         console.log(errorThrown.toString());
     });
}

$(function(){
    
    //side navigation and content setup
    $('.open').click(function () {
        if( $(".sidenav"))
            $(".sidenav").toggleClass("sidenavs");
      
        })
        
   $('.closebtn').click(function ()  {
       if( $(".sidenavs"))
            $(".sidenavs").removeClass("sidenavs");
        
    });
    
    $('.w').click(function ()  {
         $(".weather").addClass("dw");
          $(".sidenavs").removeClass("sidenavs");
    })
    
    $('.weather-content .close').click(function ()  {
         $(".weather").removeClass("dw")
    })
    
    // configure typeahead
    // https://github.com/twitter/typeahead.js/blob/master/doc/jquery_typeahead.md
     $("#city").typeahead({
        autoselect: true,
        highlight: true,
        minLength: 2
    },
    {
        source: search,
        async:true,
        templates: {
            empty: "no places found yet",
            suggestion: _.template("<span><strong><%- place_name %></strong>, <%- admin_code1 %></span>")
        }
    });
    
    //collect  selected value (state,city)
   // var path = "https://api.wunderground.com/api/86f4bf6882b36312/forecast10day/q/TX/Texas%20city.json"
    
    $("#city").on("typeahead:selected", function(eventObject, suggestion, name) {
            //skip
            //$("#city").css("display","none")
            //$(".head").css("display","block")
            
            //suggestion return json object of the state
            console.log(suggestion)
            console.log(suggestion.admin_name1)
           
            //request weather api
            var weather = new XMLHttpRequest();
             
            var state = suggestion.admin_code1
            var name = suggestion.admin_name1
            var city = suggestion.place_name
            console.log(city)
            console.log(path)
            //api path
            var url = "https://api.wunderground.com/api/86f4bf6882b36312/forecast10day/q/"
            var path = url + state + "/" + city + ".json";
            
            console.log(path);
            
            //parse json package 
            weather.open("GET", path, false);
            weather.send(null);
            var json = JSON.parse(weather.response);
            console.log(json)
            
            //chopping and dicing
            var data = json.forecast.simpleforecast.forecastday[0]
            var icon = data.icon_url 
            var text = data.conditions
            var weekday = data.date.weekday
            var temp_c = data.high.celsius
            var temp_f = data.high.fahrenheit
            var hum = data.avehumidity
            var wind = data.avewind.kph 
            var forecast = json.forecast.simpleforecast.forecastday
            console.log(forecast)
            var len = forecast.length;
            
            //populate each image 
            $('.days li img').slice(0,len).each(function(i,el){
               $(this).attr("src",forecast[i].icon_url);
            });
            
            //populate li ( high and low temp)
            $('.days li p').slice(0,len).each(function(i,el){
               $(this).html(forecast[i].high.celsius + "<sup>&deg</sup>");
            });
            $('.days li p').slice(0,len).each(function(i,el){
               $(this).append(" | ",forecast[i].low.celsius + "<sup>&deg</sup>");
            });
            
            //change the temp unit
            $('.f').click(function(){
                
                $('.text h1 span').text( function(i,txt) {console.log(i); return txt.replace(temp_c,temp_f); });
                    $('.days li p').slice(0,len).each(function(i,el){
                    $(this).html(forecast[i].high.fahrenheit + "<sup>&deg</sup>");
                });
                $('.days li p').slice(0,len).each(function(i,el){
                   $(this).append(" | ",forecast[i].low.fahrenheit + "<sup>&deg</sup>");
                });
            
                
            })
            $('.c').click(function(){
                $('.text h1 span').text( function(i,txt) {return txt.replace(temp_f,temp_c)});
                    $('.days li p').slice(0,len).each(function(i,el){
                    $(this).html(forecast[i].high.celsius + "<sup>&deg</sup>");
                });
                $('.days li p').slice(0,len).each(function(i,el){
                   $(this).append(" | ",forecast[i].low.celsius + "<sup>&deg</sup>");
                });
            })
            //insert values into tags
            
            $(".place").html(city + ", " + name)
            
            $(".icon img").attr("src" , icon )
            $(".week").html(weekday)
            $(".condition").html(text) 
            $(".hum").html("Humidity  : " + hum + "%")
            $(".wind").html("Wind : " + wind + " km/h")
            $(".text h1 span").text(temp_c)
            //$(".sun h1").html(temp + "<sup>0</sup>")*/
           
           
              
     
            
       
        });
    
})

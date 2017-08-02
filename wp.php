<?include('mfunk_1.inc');?>
<!DOCTYPE html>
<html>
<head>

<title>Fruškoj gori</title>
<meta name="Description" content="Iznajmljivanje Sony PlayStation  Novi Sad - Iznajmite Sony PlayStation 2 PS2, Sony PlayStation 3 PS3, Sony PlayStation 4 PS4 u Novom Sadu - 064 10 90 745">
<meta name="Keywords" content="iznajmljivanje, izdavanje, playstation, pes, ps2, ps3, ps4, novi sad, iznajmljivanje sony playstation novi sad, plejstejšn,  soni">
<meta name="Author" content="PlayStation PS Novi Sad Team">
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta name="Revisit-After" content="30 days">
<meta name="Robots" content="INDEX,FOLLOW">
<meta name=viewport content="width=device-width, initial-scale=1">
<!-- Facebook Open Graph Meta Tags -->
<meta property="og:title" content="Iznajmljivanje Sony PlayStation  - Novi Sad" >
<meta property="og:type" content="website" >
<meta property="og:url" content="http://tic-tac-toe.joker007.net/tic_tac_toe_game_online!menu.php" >
<meta property="og:image" content="http://tic-tac-toe.joker007.net/img-m/meni/tic_tac_toe_game_online!tic-tac-toe.png" >
<meta property="og:description" content="Iznajmljivanje Sony PlayStation  Novi Sad - Iznajmite Sony PlayStation 2 PS2, Sony PlayStation 3 PS3, Sony PlayStation 4 PS4 u Novom Sadu - 064 10 90 745" >
<link rel="icon" type="image/png" href="./favicon.ico" >
<link rel="stylesheet" href="99.css" />


<!-- Core CSS file -->
<link rel="stylesheet" href="./dist/photoswipe.css"> 

<!-- Skin CSS file (styling of UI - buttons, caption, etc.)
     In the folder of skin CSS file there are also:
     - .png and .svg icons sprite, 
     - preloader.gif (for browsers that do not support CSS animations) -->
<link rel="stylesheet" href="./dist/default-skin/default-skin.css"> 

<!-- Core JS file -->
<script src="./dist/photoswipe.min.js"></script> 

<!-- UI JS file -->
<script src="./dist/photoswipe-ui-default.min.js"></script> 
</head>

</head>


<body>
	<img src="bg21.jpg" class="bg">
	<!--<img src="./img-m/IMG_0755a.JPG" class="bg">-->
	
<div class="chead">
	<div class="dh_left">
	<div style="text-align:right;float:right;margin-top:10px;margin-right:10px;">
			<a href="50.html"><img class="img_zast"  src="./img-m/serbia_64.png"></a>
			<a href="50.html"><img class="img_zast" src="./img-m/united_kingdom_64.png"></a>
			<a href="50.html"><img class="img_zast"  src="./img-m/germany_64.png"></a>
			<a href="50.html"><img class="img_zast"  src="./img-m/russia_64.png"></a>
			<a href="50.html"><img class="img_zast"  src="./img-m/slovenia_64.png"></a>
		</div>	

	<h1 class="h1bott" style="font-size:18px;margin-left:3%;"></h1>
	</div>	
	<div class="dh_center">
		<!--<img src="./css/izdavanje-sony-playstation-novi-sad-tara.jpg" style="height:120px;" alt="Iznajmljivanje Sony PlayStation  - Izdavanje PS2 PS3 PS4 - Novi Sad - Logo" title="Iznajmljivanje Sony PlayStation  - Izdavanje PS2 PS3 PS4 - Novi Sad - Logo">-->
		<h1 class="h1bott" >FRUŠKOJ GORI</h1>
	</div>	
	<div class="dh_right">
			<h1 class="h1bott" style="font-size:18px;margin-right:2%;">Planinari slaninari i Staze zdravlja<span class="telbr"></span></h2>
			</h4>
		
	</div>	
</div>


<div class="cmeni" style="text-align: center;">
	<div class="menidiv"><a href="10.html"  class="meni">Početna</a></div><div class="menidiv"><a href="20.html"  class="meni">O&nbsp;Fruškoj&nbsp;gori</a></div><div class="menidiv"><a href="30.html" class="meni">Sadržaj</a></div><div class="menidiv"><a href="40.html" class="meni">Mapa</a></div>
</div>	



<div class="ctext2">

<br>
<h1 class="centh1"><?printf("%s",$_REQUEST["wp"]);?></h1>
</div>

	<div class="ctext2">
	<div class="dh_center siv_poz">
	<h2> 
<!--	Vrsta: Geografija -> pećina | Lokacija:Popovica | link na mapu-->

	</h2>
</div>
<div class="dh_center siv_poz">
<?

$ime=$_REQUEST["wp"];


 $ime=mf_zamena_skini_kukice(1,$ime);
 $ime=str_replace(" ", "_", $ime);
 $ime=strtolower($ime);


	$fl_image_path="./wp/".$ime."/text.txt";
	if (file_exists($fl_image_path)) {
//printf("<a href=\"%s\">%s</a>",$fime,$fime);
	echo file_get_contents($fl_image_path);
    
	} else {
  
	}
		


?>
</div>
</div>

<br>
<br>

	
	      <div id="demo-test-gallery" class="demo-gallery" style="position:relative;margin-top:30px;width:100%; text-align: center;">

        
<?  
	      ///////////////////// LABEL 12 START - Show all images from dir

$fl_dir_path="./wp/".$ime."/";
if (file_exists($fl_dir_path)) {

$d = dir($fl_dir_path);


$kj=0;

while (false !== ($entry = $d->read())) {
    if(!is_dir($entry)){
      if (strcasecmp(mb_substr($entry,0,3),"tn_")) {       	
     	 if (!strcasecmp(mb_substr($entry,-4),".jpg")) {
        	$nizjpg[$kj]=$entry;
	   	  	$kj++;      
    	 }   
      } 
    }//if((!is_dir($entry)){
}
$d->close();
//////////////

reset ($nizjpg);
while (list ($tkey, $tval) = each ($nizjpg)) { 
//printf("<hr>%s",$tval);
  
  $img_src="./wp/".$ime."/".$tval;

   printf("<a style=\"display:inline-block; margin:10px;\" href=\"%s\" data-size=\"1024x768\" data-med=\"%s\" data-med-size=\"1024x768\" data-author=\"Fruška gora\" >",$img_src,$img_src);
	 printf("         <img class=\"img_small2\" src=\"%s\" alt=\"\" />",$img_src);
	 printf("         <figure style=\"display:none;\">Fruška gora</figure>");
printf("	        </a>");
 
  } 
  
}//if
?>     
	    
      
<!--	        
 <a style="display:inline-block; margin:10px;" href="./img1/31.jpg" data-size="1024x768" data-med="./img1/31.jpg" data-med-size="1024x768" data-author="Fruška gora" >
	          <img class="img_small2" src="./img1/tn_31.jpg" alt="" />
	          <figure style="display:none;">Fruška gora</figure>
	        </a>

	           <a style="display:inline-block; margin:10px;" href="./img1/32.jpg" data-size="1024x768" data-med="./img1/32.jpg" data-med-size="1024x768" data-author="Fruška gora" >
	          <img class="img_small2" src="./img1/tn_32.jpg" alt="" />
	          <figure style="display:none;">Fruška gora</figure>
	        </a>
	        
	        
	 <a style="display:inline-block; margin:10px;" href="./img1/33.jpg" data-size="1024x768" data-med="./img1/33.jpg" data-med-size="1024x768" data-author="Fruška gora" >
	          <img class="img_small2" src="./img1/tn_33.jpg" alt="" />
	          <figure style="display:none;">Fruška gora</figure>
	        </a>

	           <a style="display:inline-block; margin:10px;" href="./img1/34.jpg" data-size="1024x768" data-med="./img1/34.jpg" data-med-size="1024x768" data-author="Fruška gora" >
	          <img class="img_small2" src="./img1/tn_34.jpg" alt="" />
	          <figure style="display:none;">Fruška gora</figure>
	        </a>
	        
	
 <a style="display:inline-block; margin:10px;" href="./img1/35.jpg" data-size="1024x768" data-med="./img1/35.jpg" data-med-size="1024x768" data-author="Fruška gora" >
	          <img class="img_small2" src="./img1/tn_35.jpg" alt="" />
	          <figure style="display:none;">Fruška gora</figure>
	        </a>

-->
	
</div>

</div>


    	<div class="joinclear">
    		    </div>

	<div class="cfoot">
		Fruškoj gori - Planinari slaninari i Staze zdravlja
</div>


    
    

    <div id="gallery" class="pswp" tabindex="-1" role="dialog" aria-hidden="true">
        <div class="pswp__bg"></div>

        <div class="pswp__scroll-wrap">

          <div class="pswp__container">
			<div class="pswp__item"></div>
			<div class="pswp__item"></div>
			<div class="pswp__item"></div>
          </div>

          <div class="pswp__ui pswp__ui--hidden">

            <div class="pswp__top-bar">

				<div class="pswp__counter"></div>

				<button class="pswp__button pswp__button--close" title="Close (Esc)"></button>

				<button class="pswp__button pswp__button--share" title="Share"></button>

				<button class="pswp__button pswp__button--fs" title="Toggle fullscreen"></button>

				<button class="pswp__button pswp__button--zoom" title="Zoom in/out"></button>

				<div class="pswp__preloader">
					<div class="pswp__preloader__icn">
					  <div class="pswp__preloader__cut">
					    <div class="pswp__preloader__donut"></div>
					  </div>
					</div>
				</div>
            </div>


			<!-- <div class="pswp__loading-indicator"><div class="pswp__loading-indicator__line"></div></div> -->

            <div class="pswp__share-modal pswp__share-modal--hidden pswp__single-tap">
	            <div class="pswp__share-tooltip">
					<!-- <a href="#" class="pswp__share--facebook"></a>
					<a href="#" class="pswp__share--twitter"></a>
					<a href="#" class="pswp__share--pinterest"></a>
					<a href="#" download class="pswp__share--download"></a> -->
	            </div>
	        </div>

            <button class="pswp__button pswp__button--arrow--left" title="Previous (arrow left)"></button>
            <button class="pswp__button pswp__button--arrow--right" title="Next (arrow right)"></button>
            <div class="pswp__caption">
              <div class="pswp__caption__center">
              </div>
            </div>
          </div>

        </div>


    </div>
    
  
    <script type="text/javascript">
    (function() {

		var initPhotoSwipeFromDOM = function(gallerySelector) {

			var parseThumbnailElements = function(el) {
			    var thumbElements = el.childNodes,
			        numNodes = thumbElements.length,
			        items = [],
			        el,
			        childElements,
			        thumbnailEl,
			        size,
			        item;

			    for(var i = 0; i < numNodes; i++) {
			        el = thumbElements[i];

			        // include only element nodes 
			        if(el.nodeType !== 1) {
			          continue;
			        }

			        childElements = el.children;

			        size = el.getAttribute('data-size').split('x');

			        // create slide object
			        item = {
						src: el.getAttribute('href'),
						w: parseInt(size[0], 10),
						h: parseInt(size[1], 10),
						author: el.getAttribute('data-author')
			        };

			        item.el = el; // save link to element for getThumbBoundsFn

			        if(childElements.length > 0) {
			          item.msrc = childElements[0].getAttribute('src'); // thumbnail url
			          if(childElements.length > 1) {
			              item.title = childElements[1].innerHTML; // caption (contents of figure)
			          }
			        }


					var mediumSrc = el.getAttribute('data-med');
		          	if(mediumSrc) {
		            	size = el.getAttribute('data-med-size').split('x');
		            	// "medium-sized" image
		            	item.m = {
		              		src: mediumSrc,
		              		w: parseInt(size[0], 10),
		              		h: parseInt(size[1], 10)
		            	};
		          	}
		          	// original image
		          	item.o = {
		          		src: item.src,
		          		w: item.w,
		          		h: item.h
		          	};

			        items.push(item);
			    }

			    return items;
			};

			// find nearest parent element
			var closest = function closest(el, fn) {
			    return el && ( fn(el) ? el : closest(el.parentNode, fn) );
			};

			var onThumbnailsClick = function(e) {
			    e = e || window.event;
			    e.preventDefault ? e.preventDefault() : e.returnValue = false;

			    var eTarget = e.target || e.srcElement;

			    var clickedListItem = closest(eTarget, function(el) {
			        return el.tagName === 'A';
			    });

			    if(!clickedListItem) {
			        return;
			    }

			    var clickedGallery = clickedListItem.parentNode;

			    var childNodes = clickedListItem.parentNode.childNodes,
			        numChildNodes = childNodes.length,
			        nodeIndex = 0,
			        index;

			    for (var i = 0; i < numChildNodes; i++) {
			        if(childNodes[i].nodeType !== 1) { 
			            continue; 
			        }

			        if(childNodes[i] === clickedListItem) {
			            index = nodeIndex;
			            break;
			        }
			        nodeIndex++;
			    }

			    if(index >= 0) {
			        openPhotoSwipe( index, clickedGallery );
			    }
			    return false;
			};

			var photoswipeParseHash = function() {
				var hash = window.location.hash.substring(1),
			    params = {};

			    if(hash.length < 5) { // pid=1
			        return params;
			    }

			    var vars = hash.split('&');
			    for (var i = 0; i < vars.length; i++) {
			        if(!vars[i]) {
			            continue;
			        }
			        var pair = vars[i].split('=');  
			        if(pair.length < 2) {
			            continue;
			        }           
			        params[pair[0]] = pair[1];
			    }

			    if(params.gid) {
			    	params.gid = parseInt(params.gid, 10);
			    }

			    return params;
			};

			var openPhotoSwipe = function(index, galleryElement, disableAnimation, fromURL) {
			    var pswpElement = document.querySelectorAll('.pswp')[0],
			        gallery,
			        options,
			        items;

				items = parseThumbnailElements(galleryElement);

			    // define options (if needed)
			    options = {

			        galleryUID: galleryElement.getAttribute('data-pswp-uid'),

			        getThumbBoundsFn: function(index) {
			            // See Options->getThumbBoundsFn section of docs for more info
			            var thumbnail = items[index].el.children[0],
			                pageYScroll = window.pageYOffset || document.documentElement.scrollTop,
			                rect = thumbnail.getBoundingClientRect(); 

			            return {x:rect.left, y:rect.top + pageYScroll, w:rect.width};
			        },

			        addCaptionHTMLFn: function(item, captionEl, isFake) {
						if(!item.title) {
							captionEl.children[0].innerText = '';
							return false;
						}
						captionEl.children[0].innerHTML = item.title +  '<br/><small>Photo: ' + item.author + '</small>';
						return true;
			        }
					
			    };


			    if(fromURL) {
			    	if(options.galleryPIDs) {
			    		// parse real index when custom PIDs are used 
			    		// http://photoswipe.com/documentation/faq.html#custom-pid-in-url
			    		for(var j = 0; j < items.length; j++) {
			    			if(items[j].pid == index) {
			    				options.index = j;
			    				break;
			    			}
			    		}
				    } else {
				    	options.index = parseInt(index, 10) - 1;
				    }
			    } else {
			    	options.index = parseInt(index, 10);
			    }

			    // exit if index not found
			    if( isNaN(options.index) ) {
			    	return;
			    }



				var radios = document.getElementsByName('gallery-style');
				for (var i = 0, length = radios.length; i < length; i++) {
				    if (radios[i].checked) {
				        if(radios[i].id == 'radio-all-controls') {

				        } else if(radios[i].id == 'radio-minimal-black') {
				        	options.mainClass = 'pswp--minimal--dark';
					        options.barsSize = {top:0,bottom:0};
							options.captionEl = false;
							options.fullscreenEl = false;
							options.shareEl = false;
							options.bgOpacity = 0.85;
							options.tapToClose = true;
							options.tapToToggleControls = false;
				        }
				        break;
				    }
				}

			    if(disableAnimation) {
			        options.showAnimationDuration = 0;
			    }

			    // Pass data to PhotoSwipe and initialize it
			    gallery = new PhotoSwipe( pswpElement, PhotoSwipeUI_Default, items, options);

			    // see: http://photoswipe.com/documentation/responsive-images.html
				var realViewportWidth,
				    useLargeImages = false,
				    firstResize = true,
				    imageSrcWillChange;

				gallery.listen('beforeResize', function() {

					var dpiRatio = window.devicePixelRatio ? window.devicePixelRatio : 1;
					dpiRatio = Math.min(dpiRatio, 2.5);
				    realViewportWidth = gallery.viewportSize.x * dpiRatio;


				    if(realViewportWidth >= 1200 || (!gallery.likelyTouchDevice && realViewportWidth > 800) || screen.width > 1200 ) {
				    	if(!useLargeImages) {
				    		useLargeImages = true;
				        	imageSrcWillChange = true;
				    	}
				        
				    } else {
				    	if(useLargeImages) {
				    		useLargeImages = false;
				        	imageSrcWillChange = true;
				    	}
				    }

				    if(imageSrcWillChange && !firstResize) {
				        gallery.invalidateCurrItems();
				    }

				    if(firstResize) {
				        firstResize = false;
				    }

				    imageSrcWillChange = false;

				});

				gallery.listen('gettingData', function(index, item) {
				    if( useLargeImages ) {
				        item.src = item.o.src;
				        item.w = item.o.w;
				        item.h = item.o.h;
				    } else {
				        item.src = item.m.src;
				        item.w = item.m.w;
				        item.h = item.m.h;
				    }
				});

			    gallery.init();
			};

			// select all gallery elements
			var galleryElements = document.querySelectorAll( gallerySelector );
			for(var i = 0, l = galleryElements.length; i < l; i++) {
				galleryElements[i].setAttribute('data-pswp-uid', i+1);
				galleryElements[i].onclick = onThumbnailsClick;
			}

			// Parse URL and open gallery if it contains #&pid=3&gid=1
			var hashData = photoswipeParseHash();
			if(hashData.pid && hashData.gid) {
				openPhotoSwipe( hashData.pid,  galleryElements[ hashData.gid - 1 ], true, true );
			}
		};

		initPhotoSwipeFromDOM('.demo-gallery');

	})();

	</script>




</body>
</html>



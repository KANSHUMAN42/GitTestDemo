
// console.log("happy") ; 
goodevening("ankit") 
goodmorning("anshuman") ;

var  goodmorning = function(name){
    console.log('Good Morning' + name) ; 
}
var goodevening = function (name){
    console.log("goodevening"+ name ) 

}

// goodevening("ankit") 
// goodmorning("anshuman") ;

// here when we use var , call function earlier to it gives error of not a function bcause of undeined type 
// let will give error too but of the type (like call before declare)
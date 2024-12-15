let bird = document.querySelector("img");

class Bird {
    #leftValue;
    #intervalId;
    #topValue;
    constructor(left,top) {
        this.left = left; 
        this.top=top;
        this.#leftValue = this.left; 
        this.#topValue=this.top;
        bird.style.position = "absolute"; 
        bird.style.left = `${this.left}px`; 
        bird.style.top=`${this.top}px`;
        
    }

    moveRight() {
        this.#intervalId = setInterval(() => {
            this.#leftValue += 20;

            if (this.#leftValue + bird.offsetWidth<= 20+window.innerWidth) {
                bird.style.left = `${this.#leftValue}px`;
            } else {
                clearInterval(this.#intervalId)
                this.#leftValue=0;
                bird.style.left = `${this.#leftValue}px`;
                this.moveRight();
                clearInterval(this.#intervalId);
                
            }
        }, 100);
    }
    falling(){
        bird.src="../images/falling.gif";
        clearInterval(this.#intervalId); 
        this.#intervalId = setInterval(() => {
            this.#topValue += 20;

            if (this.#topValue + bird.offsetHeight <= window.innerHeight) {
                bird.style.top = `${this.#topValue}px`;
            } else {
                
                clearInterval(intervalId);  
            }
            
        }, 100);
    }
   
    
}


let flyingBird = new Bird(0,0); 
flyingBird.moveRight();
window.addEventListener("load",function(){
    bird.addEventListener("click",function(){
   
        flyingBird.falling()
    });
})




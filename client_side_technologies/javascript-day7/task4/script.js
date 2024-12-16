
let bird=document.createElement("img");

class Bird {
    #leftValue;
    #topValue;
    #intervalId;


    constructor(left, top) {
        this.left = left;
        this.top = top;
        this.#leftValue = this.left;
        this.#topValue = this.top;

        bird.src="../images/R.gif";
        bird.width=200;
        bird.height=200;

        bird.style.position = "absolute";
        bird.style.left = Math.random() * (window.innerWidth-50) + "px";
        bird.style.top = `${this.top}px`;
        
        document.body.appendChild(bird);
    }

    moveRight() {
        this.stop();

        this.#intervalId = setInterval(() => {
            this.#leftValue += 20;

            if (this.#leftValue + bird.offsetWidth <= window.innerWidth) {
                bird.style.left = `${this.#leftValue}px`;
            } else {
                this.#leftValue = 0; 
                bird.style.left = `${this.#leftValue}px`;
            }
        }, 100);
    }

    stop() {
        clearInterval(this.#intervalId);
    }

    falling() {
        bird.src = "../images/falling.gif"; 
        this.stop(); 

        this.#intervalId = setInterval(() => {
            this.#topValue += 20;

            if (this.#topValue + bird.offsetHeight <= window.innerHeight) {
                bird.style.top = `${this.#topValue}px`;
            } else {
                this.#topValue = 0;
                clearInterval(this.#intervalId); 
                
            }
        }, 100);
    }
}

let flyingBird = new Bird(0, 0);
flyingBird.moveRight();

window.addEventListener("load", function () {
    bird.addEventListener("click", function () {
        flyingBird.falling();
    });
});




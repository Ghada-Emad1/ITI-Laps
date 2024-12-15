let basket = document.querySelector(".eggPacket");
let fallEgg = document.querySelector(".egg");

class Basket {
    #leftValue;

    constructor(left, bottom) {
        this.left = left;
        this.bottom = bottom;
        basket.style.position = "absolute";
        basket.style.left = `${this.left}px`;
        basket.style.bottom = `${this.bottom}px`;
        this.#leftValue = this.left;
    }

    moveRight() {
        this.#leftValue += 20;
        if (this.#leftValue + basket.offsetWidth <= window.innerWidth) {
            basket.style.left = `${this.#leftValue}px`;
        }
         else {
            this.#leftValue -= 20;
        }
    }

    moveLeft() {
        this.#leftValue -= 20;

        if (this.#leftValue >= 0) {
            basket.style.left = `${this.#leftValue}px`;
        } else {
            this.#leftValue += 20;
        }
    }
}

class Fall {
    #topValue;

    constructor(left, top) {
        this.left = left;
        this.top = top;
        fallEgg.style.position = "absolute";
        fallEgg.style.left = Math.random()*window.innerWidth+"px";
        fallEgg.style.top = `${this.top}px`;
        this.#topValue = this.top;
    }

    falling() {
        console.log("falling");
        let intervalId = setInterval(() => {
            this.#topValue += 20;

            if (this.#topValue + fallEgg.offsetHeight <= window.innerHeight) {
                fallEgg.style.top = `${this.#topValue}px`;
            } else {
                fallEgg.src = "../images/broken_egg.jpeg"; 
                clearInterval(intervalId);  
            }
            let basketRect = basket.getBoundingClientRect();
            let fallEggRect = fallEgg.getBoundingClientRect();
            console.log(basketRect)
            if (
                fallEggRect.bottom>= basketRect.top &&
                fallEggRect.top <= basketRect.bottom &&
                fallEggRect.left <= basketRect.right &&
                fallEggRect.right >= basketRect.left
            ) {
                fallEgg.style.display = "none"; 
                clearInterval(intervalId);
            }
        }, 200);
    }
}

let basketing = new Basket(100, 100);
let fallEggy = new Fall(100, 100);
fallEggy.falling();

document.addEventListener("keydown", function (e) {
    if (e.key === "ArrowLeft") {
        basketing.moveLeft();
    }
    if (e.key === "ArrowRight") {
        basketing.moveRight();
    }
});

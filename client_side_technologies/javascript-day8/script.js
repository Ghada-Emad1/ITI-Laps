let data = document.createElement("div");

const fetchCountryData = function (countryName) {
    fetch(`https://restcountries.com/v2/name/${countryName}`)
        .then(response => {
           
            return response.json();
        })
        .then(countryData => {
            const country = countryData[0];
            let createImg = document.createElement("img");
            createImg.src = country.flag;
            createImg.style.width = "300px";
            createImg.style.height = "300px";

            data.innerHTML = `
                <h1>Name: ${country.name}</h1>
                <span>Region: ${country.subregion}</span>
                <p>Population: ${country.population}</p>
                <p>Language: ${country.languages[0].name}</p>
                <p>Currency: ${country.currencies[0].name}</p>
            `;
            document.body.appendChild(createImg);
            document.body.appendChild(data);
            console.log(country)

            if (country.borders && country.borders.length > 0) {
                const neighborCode = country.borders[1];
                return fetch(`https://restcountries.com/v2/alpha/${neighborCode}`);
            }
        })
        .then(response => {

            return response.json();
        })
        .then(neighborData => {
            console.log(neighborData.flag);
            let neighborImg = document.createElement("img");
            neighborImg.src = neighborData.flag;
            neighborImg.style.width = "300px";
            neighborImg.style.height = "300px";

            let neighborDataDiv = document.createElement("div");
            neighborDataDiv.innerHTML = `
                <h1>Neighbor: ${neighborData.name}</h1>
                <span>Region: ${neighborData.subregion}</span>
                <p>Population: ${neighborData.population}</p>
                <p>Language: ${neighborData.languages[0].name}</p>
                <p>Currency: ${neighborData.currencies[0].name}</p>
            `;
            document.body.appendChild(neighborImg);
            document.body.appendChild(neighborDataDiv);
        })
        .catch(error => {
            console.error(error.message);
        });
};


fetchCountryData("Egypt");
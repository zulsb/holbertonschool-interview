#!/usr/bin/node
let request = require('request');
let url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

function getRequestStar(charactersUrl) {
    return new Promise((resolve, reject) => {
        request(charactersUrl, (error, response, body) => {
            if (error) reject(error);
            resolve(JSON.parse(body));
        });
    });
}

async function getCharactersName() {
    let response = await getRequestStar(url);
    for (let i = 0; i < response.characters.length; i++) {
        let char = await getRequestStar(response.characters[i]);
        console.log(char.name);
    }
}

getCharactersName();

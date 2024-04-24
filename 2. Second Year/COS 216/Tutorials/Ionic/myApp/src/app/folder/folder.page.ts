import { Component, OnInit } from '@angular/core';
// import { Interface } from 'readline';

interface VideoGame {
  title : string;
  price : number;
  cart : boolean;
}

@Component({
  selector: 'app-folder',
  templateUrl: './folder.page.html',
  styleUrls: ['./folder.page.scss'],
})
export class FolderPage implements OnInit {
  videogames: VideoGame[] = [];
  cartCount: number = 0;

  constructor() {}

  ngOnInit() {
    this.videogames = [
      { title: 'some title1', price: 500.0, cart: false },
      { title: 'some title2', price: 650.0, cart: false },
      { title: 'some title3', price: 899.99, cart: false },
      { title: 'some title4', price: 779.99, cart: false },
    ];
  }

  addToCart(game: VideoGame) {
    game.cart = true;
    this.cartCount++;
  }

  removeFromCart(game: VideoGame) {
    game.cart = false;
    this.cartCount--;
  }
}

// Post Request
// doPost()
// {
//   this.http.post("https://postman-echo.com/post",{ "ID": 216, "API_key": this.nativeStorgage.getItem("API key")},
//   { "Content-Type": "applications/json" })
//   .then((Response) => 
//   {
//     this.id = Response.data.id;
//     this.name = Response.data.name;
//     this.screenshots = Response.data.screenshots;
//   })
//     .catch((error) => {
//     console.log(error.status);
//     console.log(error.error); // error message as string
//     console.log(error.headers);
//   });
// }

// interface Module 
// {
//   code : string | number;
//   name : string;
//   description : string;
//   prerequisites : string[] | number[];
//   assesment : "SUMMATIVE" | "FORMATIVE";
//   year : number;
//   period : "Q1" | "Q2" | "S1" | "Q3" | "Q4" | "S2";
//   submin? : number;
//   active : boolean;
// }

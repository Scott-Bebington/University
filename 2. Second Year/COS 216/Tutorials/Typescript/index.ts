export class HomeComponent implements OnInit {
    counter: number = 0;
    constructor() {
    }
    ngOnInit(): void {
    }
    count() {
    this.counter++;
    }
    }
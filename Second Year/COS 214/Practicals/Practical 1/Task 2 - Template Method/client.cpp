#include <iostream>
#include "consumer.h"
#include "consumerCreator.h"

using namespace std;

void Odata();
void JSON();

int main() {
    
    Odata();
    JSON();

    return 0;
}

void Odata() {
    string consumerType = "OData"; // Set this to "OData" or "JSON"

    string data = "<section>\nsection 1\n<section>\nsection 2\nsection 3\n<section>\nsection 4\n</section>\n</section>\nsection 5\n</section>";
    
    // string data = "";

    //  <section>
    //      section 1
    //      <section>
    //          section 2
    //          section 3
    //          <section>
    //              section 4
    //          </section>
    //      </section>
    //      section 5
    //  </section>

    consumerCreator creator;
    creator.setConsumer(consumerType);

    consumer* consumerObj = creator.createConsumer();
    if (consumerObj) 
    {
        cout << endl;
        consumerObj->printData(data);
        cout << endl;
    } 
    else 
    {
        cout << "Invalid consumer type!" << endl;
    }
}

void JSON() {
    string consumerType = "JSON"; // Set this to "OData" or "JSON"
    
    string data = "{\nsection 1\n{\nsection 2\nsection 3\n{\nsection 4\n}\n}\nsection 5\n}";

    // string data = "";

    //  {
    //      section 1
    //      {
    //          section 2
    //          section 3
    //          {
    //              section 4
    //          }
    //      }
    //      section 5
    //  }

    consumerCreator creator;
    creator.setConsumer(consumerType);

    consumer* consumerObj = creator.createConsumer();
    if (consumerObj) 
    {
        cout << endl;
        consumerObj->printData(data);
        cout << endl;
    } 
    else 
    {
        cout << "Invalid consumer type!" << endl;
    }
}

#include <iostream>
#include "DNSServer.h"


void prtReq(DNSServer & dnsServer, std::string domain){
    Response r = dnsServer.processRequest(domain);
    std::cout << r.source << ": " << r.domainName << "\n\t-> " << r.address << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    DNSServer dns1("DNS1");
    DNSServer dns2("DNS2", dns1);
    DNSServer dns3("DNS3", dns2);
    DNSServer dns4("DNS4", dns3);
    DNSServer dns5("DNS5", dns4);

    dns1.addDomain("franspaco.com", "173.201.141.1");
    dns1.addDomain("microsoft.com", "191.239.213.197");
    dns1.addDomain("google.com", "201.151.207.45");

    dns2.addDomain("facebook.com", "31.13.66.36");
    dns2.addDomain("stackoverflow.com", "151.101.65.69");

    dns3.addDomain("wikipedia.org", "208.80.153.224");
    dns3.addDomain("firstinspires.org", "216.146.46.10");

    dns4.addDomain("tec.mx", "104.210.149.110");
    dns4.addDomain("youtube.com", "201.151.207.57");

    dns5.addDomain("amazon.com", "54.239.25.192");
    dns5.addDomain("netflix.com", "107.21.48.181");


    prtReq(dns5, "franspaco.com");
    prtReq(dns5, "google.com");
    prtReq(dns5, "stackoverflow.com");
    prtReq(dns5, "microsoft.com");
    prtReq(dns5, "microsoft.com");
    prtReq(dns5, "gmail.com");
    prtReq(dns5, "netflix.com");
    prtReq(dns5, "wikipedia.org");
    prtReq(dns5, "twitter.com");
    prtReq(dns5, "twitter.com");

    dns5.prtList();

    return 0;
}
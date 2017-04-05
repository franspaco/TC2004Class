//
// Created by franspaco on 5/04/17.
//

#ifndef CADENADERESPONSABILIDAD_DNSSERVER_H
#define CADENADERESPONSABILIDAD_DNSSERVER_H

#include <map>

class DNSServer {
protected:
    DNSServer * server;
    std::string name;
    std::map<std::string, std::string> dnsList;
public:
    DNSServer(std::string name){
        this->name = name;
    }
    DNSServer(std::string name, DNSServer & next){
        this->name = name;
        server = &next;
    }

    void setServer(DNSServer & next){
        server = &next;
    }

    void addDomain(std::string domain, std::string ip){
        dnsList[domain] = ip;
    }

    std::string processRequest(std::string domain){
        std::string response;
        try {
            return name + ": " + domain + "\n\t-> " + dnsList.at(domain);
        }
        catch (std::out_of_range) {
            if(server != nullptr){
                return server->processRequest(domain);
            }else{
                return name + ": NO DNS RECORD FOUND";
                //system(("nslookup " + domain + " | grep -i address:").c_str());
            }
        }
    }

};


#endif //CADENADERESPONSABILIDAD_DNSSERVER_H

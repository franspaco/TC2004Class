//
// Created by franspaco on 5/04/17.
//

#ifndef CADENADERESPONSABILIDAD_DNSSERVER_H
#define CADENADERESPONSABILIDAD_DNSSERVER_H

#include <map>
#include <regex>
#include <iostream>

// Clase respuesta utilizada para contestar
class Response {
public:
    Response(std::string dom, std::string add, std::string src) : domainName(dom), address(add), source(src) {}
    std::string domainName;
    std::string address;
    std::string source;
};

// Clase servidor DNS
class DNSServer {
private:

    // Recibe una función de sistema y regresa en string su respuesta
    // Fuente: http://stackoverflow.com/questions/2655374
    std::string getStdoutFromCommand(std::string cmd) {
        std::string data;
        FILE * stream;
        const int max_buffer = 256;
        char buffer[max_buffer];
        cmd.append(" 2>&1");

        stream = popen(cmd.c_str(), "r");
        if (stream) {
            while (!feof(stream))
                if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
            pclose(stream);
        }
        return data;
    }

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

    // Imprime mapa de dominios guardados
    void prtList(){
        std::cout << "\nDomain list in: " << name << std::endl;
        for(auto a: dnsList){
            std::cout << a.first << " -> " << a.second << std::endl;
        }
    }

    // Recibe y procesa una solicitud
    Response processRequest(std::string domain){
        std::string response;
        try {
            // Caso cuando la respuesta la tiene este servidor
            std::string ip(dnsList.at(domain).c_str());
            return Response(domain, ip, name);
        }
        catch (std::out_of_range) {
            // Si no la tiene el servidor

            if(server != nullptr){
                // Preguntar al siguiente y agregar el registro localmente
                Response response = server->processRequest(domain);
                dnsList[domain] = response.address;
                return response;

            }else{
                // Preguntar a internet y guardar la respuesta localmente

                //return name + ": NO DNS RECORD FOUND";

                std::string line;
#ifdef __linux__
                //Comandos para linux
                std::istringstream out(getStdoutFromCommand("nslookup " + domain + " | grep -i address:"));
#elif _WIN32
                // Comandos para windows
                //Creo que funciona, no pude probar
                std::istringstream out(getStdoutFromCommand("nslookup " + domain + " | findstr /R /C:\"Address\""));
                std::getline(out, line);
#endif

                std::getline(out, line);
                std::getline(out, line);

                line = line.substr(line.find(" ")+1, line.size()-1);

                dnsList[domain] = line;

                //return "Internet: " + domain + "\n\t-> " + line;
                return Response(domain, line, "Internet");
            }
        }
    }

};


#endif //CADENADERESPONSABILIDAD_DNSSERVER_H

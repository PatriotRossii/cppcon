#include <optional>

#include <string>

struct Certificate { };

struct NetworkConnection {
    Certificate getDefaultCertificate() const {
        return Certificate { };
    }

    std::optional<std::string> password_;
    std::optional<Certificate> cert_;

/*
    Certificate getCert() const {
        if(cert_.has_value()) {
            return cert_.value();
        } else {
            return getDefaultCertificate();
        }
    }
*/
/*
    Certificate getCert() const {
        if(cert_) {
            return *cert_;
        } else {
            return getDefaultCertificate();
        }
    }
*/
    Certificate getCert() const {
        return cert_.value_or(
            getDefaultCertificate()
        ); // In this version we call getDefaultCertificate before
           // testing the optional
    }
};

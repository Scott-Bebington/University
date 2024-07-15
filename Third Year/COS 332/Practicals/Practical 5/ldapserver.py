import ldap

# Set up the LDAP connection
conn = ldap.initialize('ldap://127.0.0.1')

# Bind to the LDAP server
conn.simple_bind_s()

# Perform the LDAP search
search_base = 'ou=up,dc=ac,dc=za'
search_filter = '(objectClass=organizationalUnit)'
result = conn.search_s(search_base, ldap.SCOPE_SUBTREE, search_filter)

# Retrieve the search results
for dn, entry in result:
    print(entry)

# Unbind from the LDAP server
conn.unbind_s()

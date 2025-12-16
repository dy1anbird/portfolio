In this week the setup was done as listed in the readme.  
-- Set up OptiPlex with Ubuntu and Windows 11 Pro  
-- Create Homelabadmin on Ubuntu device  
-- Create SSH in order to remote access the Homelab user from other devices:  
   - Ed25519 SSH key pair generated on the Macbook  
   - Public key copied to OptiPlex using ssh-copy-id  
   - Verified passwordless login from macbook.  
![Screenshot](/Users/dylanbird/Desktop/device_setup.png)

-- Firewall Setup
   - Enabled UFW firewall
   - Default the policy to deny incoming traffic and allow outgoing traffic
   - Allowed SSH traffic using the OpenSSH profile
   - Verified firewall status with verbose output  



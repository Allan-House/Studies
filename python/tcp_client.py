import logging
import socket

class TCPClient:
    """TCP client for establishing and managing a connection to a TCP server."""
    def __init__(self, host: str, port: int):
        """
        Initialize TCP client.

        Args:
            host: IP address of TCP server.
            port: Port number of TCP server.
        """
        self.host = host
        self.port = port
        self.socket = None

        # Connection state
        self.connected = False
        self.running = False

    def connect(self) -> bool:
        """
        Establish TCP connection to server.

        Returns:
            True if connection succesfull, false otherwise.
        """
        try:
            logging.info(f"TCPClient: Connecting to {self.host}:{self.port}...")
            self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.socket.connect((self.host, self.port))
            self.socket.setblocking(False)

            self.connected = True
            
            logging.info(f"TCPClient: Conntected to {self.host}:{self.port}")
            return True
        except TimeoutError:
            logging.error(f"TCPClient: Connection timeout to {self.host}:{self.port}")
            self._clean_up_socket()
            return False
        except OSError as e:
            logging.error(f"TCPClient: connection error: {e}")
            self._clean_up_socket()
            return False
        except Exception as e:
            logging.error(f"Unexpected error during connection: {e}")
            self._clean_up_socket()
            return False

    def disconnect(self) -> None:
        """Close TCP connection."""
        logging.info(f"TCPClient: Disconecting from {self.host}:{self.port}...")
        
        self.connected = False
        self._clean_up_socket()

        logging.info(f"TCPClient: Disconnected from {self.host}:{self.port}")
        
    def _clean_up_socket(self) -> None:
        """Clean up socket resources."""
        if self.socket:
            try:
                self.socket.close()
            except OSError as e:
                logging.error(f"TCPClient: error closing socket: {e}")
            finally:
                self.socket = None